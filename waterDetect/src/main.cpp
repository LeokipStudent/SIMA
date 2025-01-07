#include <Arduino.h>

// put function declarations here:
bool waterDetected();


//String waterPin = "A0";
int count = 0;

void setup() {
  Serial.begin(9600);
}



void loop() {
  if(waterDetected()) {
    Serial.println("Vatten upptäckt!");
  } else if(count == 5) {
    Serial.println("Inget vatten upptäckt!");
    count = 0;
  }
  
  delay(200);
}

// put function definitions here:
bool waterDetected() {
  int sensorValue = analogRead(A0); 
  float voltage = sensorValue * (5.0 / 1023.0);
  
  Serial.println("Voltage: " + String(voltage));
  return(voltage > 1.5);

}