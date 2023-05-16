/**
 * @file stepperpot_speed_control.ino
 *
 * @mainpage UTS Dobot Conveyor used by The Palletisers 
 *
 * @section description Description
 * Arduino/A4988 stepper controller 
 * with speed control and object proximity 
 * detection
 *
 * @section circuit Circuit
 * - <insert schematic here>
 * - pin 7 to e18_sensor black wire
 * - pin 6 to STEP A4988
 * - pin 5 to DIR A4988
 * - pin 4 to EN A4988
 *
 * @section libraries Libraries
 * - No libraries required
 *   
 *
 * @section notes Notes
 * - Comments are Doxygen compatible 
 *
 * @section credit CREDIT
 * - adapted from https://forum.arduino.cc/t/stepper-motor-a4988-potentiometer-speed-control/654061/2
 * - https://www.instructables.com/Project-on-E18-D80NK-IR-Proximity-Sensor-With-Ardu
 *
 * @section author Author
 * - Modified by Bryn Cahir WORKS WITH PROX SWITCH! 17/4/23.
 * - Modified by Bryn Cahir debounce added 15/5/23.
 */

// Defines pins numbers
const int e18_sensor = 7; ///< e18_sensor black wire
const int stepPin = 6; ///< to A4988
const int dirPin = 5; ///< to A4988
const int enablePin = 4;  ///< to A4988
int customDelay; // Defines variables
int intervalBetweenSteps = 1;
 
void setup() {
  // Sets the sensor as input and three motor pins as Outputs
  pinMode (e18_sensor, INPUT);
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(enablePin,OUTPUT);
 
  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
  digitalWrite(enablePin,LOW); //Enables motor
}
void loop() {
int state = digitalRead(e18_sensor); ///< gets the sensor state
if(state==LOW){
delayMicroseconds(10000); ///< this is debounce delay, to stop the belt from jittering when a pouch is detected
digitalWrite(enablePin,HIGH);
}
else {
digitalWrite(enablePin,LOW);
} 
  intervalBetweenSteps = speedUp(); ///< Gets custom delay values from the custom speedUp function
  ///< Makes pulse with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(100); ///< this is the pulse width
  digitalWrite(stepPin, LOW);
  delayMicroseconds(intervalBetweenSteps);

}
// Function for reading the Potentiometer
int speedUp() {
  int customDelay = analogRead(A0); // Reads the potentiometer

  int newCustom = map(customDelay, 0, 1020, 10,10000); // Converts the read values of the potentiometer from 0 to 1023 into desired delay values
  return newCustom;  
  
}
