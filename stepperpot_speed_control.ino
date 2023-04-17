//WORKS WITH PROX SWITCH! 17/4/23
//adapted from https://forum.arduino.cc/t/stepper-motor-a4988-potentiometer-speed-control/654061/2
//https://www.instructables.com/Project-on-E18-D80NK-IR-Proximity-Sensor-With-Ardu

// Defines pins numbers
const int e18_sensor = 7;
const int stepPin = 6;
const int dirPin = 5;
const int enablePin = 4; 
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
int state = digitalRead(e18_sensor); // gets the sensor state
if(state==LOW){
digitalWrite(enablePin,HIGH);
}
else {
digitalWrite(enablePin,LOW);
} 
  intervalBetweenSteps = speedUp(); // Gets custom delay values from the custom speedUp function
  // Makes pulse with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(100); // this is the pulse width
  digitalWrite(stepPin, LOW);
  delayMicroseconds(intervalBetweenSteps);

}
// Function for reading the Potentiometer
int speedUp() {
  int customDelay = analogRead(A0); // Reads the potentiometer

  int newCustom = map(customDelay, 0, 1020, 10,15000); // Converts the read values of the potentiometer from 0 to 1023 into desired delay values
  return newCustom;  
  
}
