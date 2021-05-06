# **Digital HVAC Controller**
## Team Member Names:

Yue Pan, Zhou Lu

Georgia Tech, Spring 2021

## Quick Links
[Demo Video Link: https://youtu.be/D2i0VEtWlDY](https://youtu.be/D2i0VEtWlDY)

[Presentation Video Link: https://youtu.be/cG2J5QSIfjU](https://youtu.be/cG2J5QSIfjU)

[Link to presentation slides](https://docs.google.com/presentation/d/1tGytIB-LjaBZmF8_X_NiC-F8N2HdAv82nXdVFpHENtE/edit?usp=sharing)

GitHub Webpage: [https://cpa872.github.io/ECE-4180-Final-Project/](https://cpa872.github.io/ECE-4180-Final-Project/)

MBED Repo Link: [https://os.mbed.com/users/cx872/code/4180-final_project/](https://os.mbed.com/users/cx872/code/4180-final_project/)




### Motivation
HVAC Control in old Apartments (e.g. North Avenue East) is achieved through a wall-mounted knob. This can be inaccurate, with an unknown set temperature value and room temperature varying in a wide range wround the "set" temperature.

It can also be inconvenient, with no remote control. We addressed these issues with a temperature-sensing HVAC controller with bluetooth remote control support.


### Parts List
* Microcontroller -- MBED

* Display -- uLCD-144G2

* Thermometer -- BME 280

* Remote Control -- Adafruit Bluefruit and companion smartphone app

* Rotation Actuator -- HITEC HS-422 Servo

* Power Supply -- Arduino power supply module (Containing Dedicated Servo power pins and oen USB 5V output for MBED)


### Source Code
Github Source Code Link: [https://github.com/CPA872/ECE-4180-Final-Project](https://github.com/CPA872/ECE-4180-Final-Project)

Mbed Repository Page Link: [https://os.mbed.com/users/cx872/code/4180-final_project/](https://os.mbed.com/users/cx872/code/4180-final_project/)


### Schematic
![Alt Text](/images/Schematic.png)

### Image Gallery
![AltText](/images/IMG_4283.jpg)
![AltText](/images/IMG_4276.JPG)
![AltText](/images/IMG_4277.JPG)
![AltText](/images/IMG_4278.JPG)
![AltText](/images/IMG_4279.JPG)
![AltText](/images/IMG_4280.JPG)
![AltText](/images/IMG_4281.JPG)
![AltText](/images/IMG_4282.JPG)

### Embedded Presentation Video
{% include youtubePlayer.html id=cG2J5QSIfjU %}
[Click Here To Play](https://youtu.be/cG2J5QSIfjU)

### Embedded Demo Video
{% include youtubePlayer.html id=D2i0VEtWlDY %}
[Click Here To Play](https://youtu.be/D2i0VEtWlDY)


### Future Work

We would like to actually use this design in our future apartment (8th Street East)

The servo needs to be more firmly fixed onto the surface

May consider replacing the power supply module because the regulator on it is very hot during operation 

Can add a “force on” feature using the 3rd button that turns on the HVAC without changing the set temperature
