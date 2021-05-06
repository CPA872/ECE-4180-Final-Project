# **Digital HVAC Controller**
## Team Member Names:

Yue Pan, Zhou Lu

Georgia Tech, Spring 2021

## Quick Links
Demo Video Link: https://youtu.be/D2i0VEtWlDY

Presentation Video Link: https://youtu.be/cG2J5QSIfjU

Link to presentation slides https://docs.google.com/presentation/d/1tGytIB-LjaBZmF8_X_NiC-F8N2HdAv82nXdVFpHENtE/edit?usp=sharing

GitHub Webpage: https://cpa872.github.io/ECE-4180-Final-Project/

MBED Repo Link: https://os.mbed.com/users/cx872/code/4180-final_project/




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

### Parts List
* Microcontroller -- MBED

* Display -- uLCD-144G2

* Thermometer -- BME 280

* Remote Control -- Adafruit Bluefruit and companion smartphone app

* Rotation Actuator -- HITEC HS-422 Servo

* Power Supply -- Arduino power supply module (Containing Dedicated Servo power pins and oen USB 5V output for MBED)


### Schematic

### Image Gallery

### Embedded Presentation Video
[![](http://img.youtube.com/vi/cG2J5QSIfjU/0.jpg)](http://www.youtube.com/watch?v=cG2J5QSIfjU "")


### Embedded Demo Video
[![](http://img.youtube.com/vi/D2i0VEtWlDY/0.jpg)](http://www.youtube.com/watch?v=D2i0VEtWlDY "")


### Future Work

We would like to actually use this design in our future apartment (8th Street East)

The servo needs to be more firmly fixed onto the surface

May consider replacing the power supply module because the regulator on it is very hot during operation 

Can add a “force on” feature using the 3rd button that turns on the HVAC without changing the set temperature
