# arduino_conveyor


Arduino/A4988 stepper controller with speed control and object proximity detection

1) Compile and upload stepperpot_speed_control.ino to an Arduino
2) find the 2 pairs of stepper motor coils via your preferred method
3) build the circuit described below and attach the motor and power
4) adjust the speed to suit the task, reverse the coil pairs if the conveyor moves the wrong way!
5) adjust the position of the proximity sensor to detect the item and stop conveyor motion

![from CB11.10.004 lab](https://github.com/Brizla/arduino_conveyor/blob/main/conveyor.jpg?raw=true)


![how to wire it up](https://github.com/Brizla/arduino_conveyor/blob/main/schematic.jpg?raw=true)

 **Arduino Nano pinout**
 
 A0 to 100k potentiometer
 
 D7 to e18_sensor black wire

 D6 to STEP A4988

 D5 to DIR A4988

 D4 to EN A4988


**Credit**
 
https://forum.arduino.cc/t/stepper-motor-a4988-potentiometer-speed-control/654061/2
  
https://www.instructables.com/Project-on-E18-D80NK-IR-Proximity-Sensor-With-Ardu
