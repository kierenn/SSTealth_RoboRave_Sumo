# SSTealth Roborave Sumo

This repository contains materials for SSTealth's self-driven vehicle model participating in the RoboRave Australia in the season 2024.

## Content
- `Models` is for the files for models used by 3D printers, laser cutting machines and CNC machines to produce the vehicle elements.
  - 'sstealth Sumo Bot.stl` contains the 3D Model of the sumo bot
- `sumo.ino` is our source code to operate the bot for the sumo challenge

## Introduction

### Usage
**ALL LIBRARIRES ARE REQUIRED FOR THE CODE TO RUN CORRECTLY**

1.⁠ ⁠In Arduino or Arduino IDE, install the libraries, `CytronMotorDriver.h` and `SharpIR.h`
2.⁠ ⁠To use the library for the motor driver, follow the following in Arduino or Arduino IDE: `Sketch --> Include Library --> Cytron Motor Drivers Library`
3. ⁠To use the library for the sharp IR, follow the following in Arduino or Arduino IDE: `Sketch --> Include Library --> SharpIR`

## Reminders before running the bot

- Software
  - Ensure that the board is set to Arduino Uno
  - Ensure serial bot rate is 9600
  - Ensure all sensor values have been calibrated to the current environmental conditions
  - Run!
- Hardware
  - Wires have been connected properly
  - Components are working properly
  - Structural parts are connected properly
  - Spaces on the wheels are correct

## Components used

1. Microcontroller: Arduino UNO x1
2. Motor Driver: SHIELD-MD10 x1
3. Motors: SPG20HP-34K x2
4. Distance Sensor: Analog Distance Sensor, SN-GP2Y0A21 x3
5. Wheels Silicone Wheels, WL-G25T1 x4
6. Line Tracking: IR Line Tracking Module x2
7. Structure: PLA+
9. Battery for Arduino: Onbo 1100mAh 35C 2S Lipo Battery x1
10. Battery for Motor Driver: TATTU FUNFLY 1550mAh 4s 100C Lipo Battery x1
