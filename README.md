# Neoπ Wireless CNC Controller (3-axis) 
![](https://github.com/saheenpalayi/NeoPI_Wireless/blob/main/Images/NeoPI-W-v1.0.jpg)
## Project Overview
This project was made for ESP32 based 3-Axis Milling Machines. I started this project During my time at the FAB LAB Kerala for an awesome project Called [FAB Neo](https://fab.cba.mit.edu/classes/865.21/people/rahul/) by Rahul s Rajan. He was developing an Open source fully compact easy to Use PCB Milling Machine Over the years.

## Fetures of Neoπ Wireless CNC Controller
- NodeMCU-32 ESP32 38 Pin  Board based Controller
- SD Card Supported
- A4988/DRV8825 and SPI TMC 2130 stepper Drivers supported
- Reverse Polarity Protection
- Over Voltage protection**
- 12v/24 compatible
- OTA Supports
- PWM Spindle Support
- 2 Probes available (PROB1 and PROB2)
- Power LED Indications RED(power) and Green (5V)

** Optional The board works even without this feature.

## Hardware Pin Mapping

| Sl No | Pin-Names | GPIO |
| --- | --- | --- |
| 1 | X_Dir | GPIO26 |
| 2 | X_Step | GPIO12 |
| 3 | Y_Dir | GPIO25 |
| 4 | Y_Step | GPIO14 |
| 5 | Z_Dir | GPIO33 |
| 6 | Z_Step | GPIO27 |
| 7 | X_limit | GPIO21 |
| 8 | Y_limit | GPIO4 |
| 9 | Z_limit | GPIO15 |
| 10 | Stepper_disable | GPIO13 |
| 11 | Spindle | GPIO17 |
| 12 | PB1 | GPIO32 |
| 13 | PB2 | GPIO22 |


## Firmware

- Use [Grbl_ESP32](https://github.com/bdring/Grbl_Esp32) with [NeoPI_W_v1.h](https://github.com/saheenpalayi/NeoPI_Wireless/blob/main/Firmware/NeoPI_W_v1.h) machine file

## Credits
The Grbl_ESP32 firmware and the ESP32 Hardware is a well-written Open source Project by [bdring](https://github.com/bdring) A K A Barton Dring.

I took reference from these two projects mentioned below
- [Grbl_ESP32_Development_Controller](https://github.com/bdring/Grbl_ESP32_Development_Controller)
- [A 4 axis ESP32 CNC controller for daisy chained SPI stepper drivers](https://github.com/bdring/4_Axis_SPI_CNC#revision-history)
## Revision History
**v1.0**
- version 1 is my first build it has some problems and fixes to do 

