# Mimicry_hand(Mine defusing bot)
The main objective of the robotic bot is the data transmission from the site of mines using a camera wirelessly on a screen and then control robot wirelessly with the help of CV.

# Work MAP
![Image alt text](Media/MAP-removebg-preview.png?raw=true "MAP")

# Elecronics used for video transmission
## Audio Visual Transmission
* TS832 FPV 5.8G 600MW 48CH (2-6S) Wireless AV Transmitter
* RC832 FPV 5.8G 600MW 48CH (2-6S) Wireless AV Transmitter

![Image alt text](Media/TS832_&_RC832_ConnectionSwitches.PNG?raw=true "TS832_&_RC832_Connection")

## 1000TVL 90 degree CMOS Camera
1000TVL 90 Degree COMS Camera can be used as both PAL and NTSC. The toggle switch is provided on the camera by which you can enjoy the operation of PAL or NTSC mode.

![Image alt text](Media/1000TVL.PNG?raw=true "1000TVL 90 degree CMOS Camera")

## Wireless Communication Module (nRF24L01)
* The nRF24L01 can be easily paired with a variety of microcontroller systems; MCU/ARM/PIC/AVR/STM32 by using the SPI protocol or an RF24 library when pairing with Arduino.
* The nRF24L01, when used with the right setup, is able to transmit wavelengths over several kilometres. However, nRF24L01+ module that’s designed with a power amplifier and IPX antenna for wireless communication of up to 1000 meters

![Image alt text](Media/Nrf.PNG?raw=true "nRF24L01 Connections")

# Computer Vision
Libraries Used For Hand Gesture Module
* Pyserial
* CvZone
* MediaPipe

![Image alt text](Media/OpenCv_handrepresentation.PNG?raw=true "Computer Vision Result")

## Battery Usage for each module
* For RC832                   LiPo 1300mah(30C 11.1V~14.7V)   3 Hr work time
* For TS832 and Camera        LiPo 1300mah(30C 11.1V~14.7V)   2.606 Hr work time
* Arduino Uno (on battery)    LiPo 1300mah(30C 7V~10V)        1.45 Hr work time
* 5 Servo motor Sg90          LiPo 1300mah(30C 3.V~14.7V)     1.20 Hr work time
