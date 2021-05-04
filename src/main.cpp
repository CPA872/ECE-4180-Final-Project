#include "mbed.h"
//#include "DHT.h"
#include "uLCD_4DGL.h"
#include "rtos.h"
#include "PinDetect.h"
#include "Servo.h"
#include "BME280.h"

uLCD_4DGL lcd(p13,p14,p19); // serial tx, serial rx, reset pin;
//DHT dht(p18, DHT22);
PinDetect bt1(p5);
PinDetect bt2(p7);
PinDetect bt3(p6);
Servo servo(p21);
Mutex lcd_mutex;
RawSerial blue(p28, p27);      //Bluetooth Module
BME280 bme(p9, p10);


float humidity;
volatile float set_temp;
float curr_temp;
volatile bool AC_on;

// two interrupts for updating the set temperature
void increment_temp() {
    if (set_temp <= 29.5)
        set_temp += 0.5;
}

void decrement_temp() {
    if (set_temp >= 16.5)
        set_temp -= 0.5;
}

// thread 1, for updating the temperature printout on LCD
void temp_update() {
     while (1) {
         lcd_mutex.lock();
            lcd.color(WHITE);
            lcd.set_font_size(2, 2);
            lcd.locate(0, 2);
            lcd.printf("%.1f ", set_temp);
        lcd_mutex.unlock();   
        
        Thread::wait(500);
    }
}

// thread 2, for comparing temperature and controlling the servo
void servo_control() {
    while (1) {
        if (curr_temp >= set_temp + 1.0f) {
            servo = 1;
            lcd_mutex.lock();
                lcd.locate(5, 6);
                lcd.color(RED);
                lcd.printf("ON ");
            lcd_mutex.unlock();
//            Thread::wait(60 * 1000);  // lock the action for at least 1 minute
            continue;
        } 
        
        if (curr_temp <= set_temp - 1.0f) {
            servo = -1;
            lcd_mutex.lock();
                lcd.locate(5, 6);
                lcd.color(RED);
                lcd.printf("OFF");
            lcd_mutex.unlock();  
        }
        
        Thread::wait(1000);   
    }
}

// thread 3, for monitoring bluetooth device and update temperature
void bluetooth_control() {
    while (1) {
//        printf("hey");
        if (blue.readable()) {
            printf("blue is readable\n");
            if (blue.getc() == 's') {
                if (blue.getc() == 'e') {
                    if (blue.getc() == 't') {
                        if (blue.getc() == ' ') {
                            printf("here!\n");
                            char msg[5];
                            msg[0] = blue.getc();
                            msg[1] = blue.getc();
                            msg[2] = blue.getc();
                            msg[3] = blue.getc();
                            msg[4] = '\0';
                            
                            sscanf(msg, "%f", &set_temp);
                            printf("%s", msg);

                        }
                    }
                }
            }
        }
//        Thread::yield();
    }   
}

int main() {
    servo = 0;
    blue.baud(9600);
    
    bt1.mode(PullUp);
    bt2.mode(PullUp);
    bt3.mode(PullUp);
    bt1.attach_deasserted(&increment_temp);
    bt2.attach_deasserted(&decrement_temp);

    bt1.setSampleFrequency();
    bt2.setSampleFrequency();
    bt3.setSampleFrequency();
    
    set_temp = 25;
    /////////////////////////
    lcd.filled_rectangle(5, 0, 60, 4, WHITE);
    lcd.filled_rectangle(65, 0, 125, 4, GREEN);
    lcd.filled_rectangle(5, 70, 60, 74, BLUE);
    lcd.filled_rectangle(65, 70, 125, 74, RED);
    /////////////////////////
    lcd.text_width(2);
    lcd.text_height(2);
    lcd.locate(0, 1);
    lcd.color(WHITE);
    lcd.printf(" SET ");
    lcd.color(GREEN);
    lcd.printf("CUR");
    lcd.locate(0, 5);
    lcd.color(BLUE);
    lcd.printf(" HUM ");
    lcd.color(RED);
    lcd.printf("ACT");
    
    Thread t1;
    Thread t2;
    Thread t3;
    
    t1.start(&temp_update);
    t2.start(&servo_control);
    t3.start(&bluetooth_control);
    
    float temp_f;
    int code;
    
    // main thread, for updating temperature and humidity printouts on LCD
    while (1) {
        curr_temp = bme.getTemperature();
//        curr_temp = (temp_f - 32.0) * 5.0 / 9.0;
        humidity = bme.getHumidity();
        
        lcd_mutex.lock();
            lcd.locate(5, 2);
            lcd.color(GREEN);
            lcd.printf("%.1f", curr_temp);
            
            lcd.locate(0, 6);
            lcd.color(BLUE);
            lcd.printf(" %.0f%% ", humidity);
        lcd_mutex.unlock();
        
        Thread::wait(2000);   
    }
}
