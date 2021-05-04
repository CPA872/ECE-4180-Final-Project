# ECE 4180 Final Project
## Digital HVAC Controller
Yue Pan, Zhou Lu
Demo Video Link: https://youtu.be/D2i0VEtWlDY
Presentation Video Link:
GitHub Webpage: https://cpa872.github.io/ECE-4180-Final-Project/
MBED Wiki Link: https://os.mbed.com/users/cx872/code/4180-final_project/



### Motivation
HVAC Control in old Apartments (e.g. North Avenue East) is achieved through a wall-mounted knob. 
Problems are:
Inaccurate:
Unknown set temperature value
Room temperature will vary in a big range around the “set” temperature
Inconvenient
No Remote Control
HVAC control knob in NAE


### Code Structure -- MBED Project
Set temperature is adjusted via interrupts on push buttons
Using RTOS with 4 threads
Prints temperature and humidity on the LCD
Compares set and current temperatures to control the servo
Actuate servo when current temperature is outside set_temp ± 1 degree Celsiusset=22.0, cur=23.1 → turns ON, until set=22.0, curr=21.9 → turns OFF
Once servo actuated, it will be locked for 1 minute prevent overheating
Prints ON/OFF under the “ACT” field on the LCD
Software polling loop for monitoring Bluetooth and change set temperature accordingly
Temperature and Humidity updating (mian thread)
Prints numbers to specific areas on the LCD

### Component Selection
Microcontroller -- MBED

    Familiar with the interface, works with components in hand

    Plenty of GPIO, PWM output, I2C and serial interfacing pins

Display -- uLCD-144G2

    Familiar with library and coding standards

    Size is perfect for such small applications and does not draw too much power

Thermometer -- BME 280

    High accuracy, easy library set up

Remote Control -- Adafruit Bluefruit

    Familiar with the interface, connection is easy to set up and usually stable

    Another option could be ESP8266 based, but the control interface must be accessible from the same subnet, which is infeasible given campus network setup

Rotation Actuator -- HITEC HS-422

    Larger torque than the more common SG-90, can rotate the knob easily

    Easily controlled via PWM

Power Supply -- Arduino power supply module 

    Mountable on breadboard and provide multiple power out pins including dedicated pin for servo

    Provides one USB 5V output to power the MBED

### Future Work

We would like to actually use this design in our future apartment (8th Street East)

The servo needs to be more firmly fixed onto the surface

May consider replacing the power supply module because the regulator on it is very hot during operation 

Can add a “force on” feature using the 3rd button that turns on the HVAC without changing the set temperature
