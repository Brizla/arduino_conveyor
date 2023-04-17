const int e18_sensor = 7;
const int led = 6;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (e18_sensor, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
int state = digitalRead(e18_sensor);
Serial.println(state);
if(state==LOW){
Serial.println("Object Detected");
digitalWrite(led, HIGH);
}
else {
Serial.println("All Clear");
}
}
