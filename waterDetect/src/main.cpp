/*
  Program to check for presence of water at homemade water sensor
  Author: Leonard
*/

#include <Arduino.h>

// put function declarations here:
float waterVoltage();
bool waterDetected();

#define waterPin A0
int count = 0;


void setup() {
  Serial.begin(9600);
}


void loop() {
  float voltage = waterVoltage();
  Serial.println("Voltage: " + String(voltage));

  if(waterDetected()) {
    Serial.println("Vatten upptäckt!");
    count = 0;
  } else if(count == 5) {
    Serial.println("Inget vatten upptäckt!");
    count = 0;
  }
  ++count;
  delay(500);
}

//Function that reads data from waterPin and converts to a voltage that is returned
float waterVoltage() {
  int sensorValue = analogRead(waterPin); 
  float voltage = sensorValue * (5.0 / 1023.0);
  return voltage;
}

//Function that checks if waterPin voltage is above a threshold
//Is this going to need a dynamic threshold?
bool waterDetected() {
  float limit = 2.0;
  float voltage = waterVoltage();
  return(voltage > limit);
}