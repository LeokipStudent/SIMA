/*
  Program to check for low voltage levels
  Author: Leonard
*/

#include <Arduino.h>

// put function declarations here:
float batteryVoltage();
bool batteryLow();

#define batteryPin A3


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  float voltage = batteryVoltage(); 
  Serial.println("Battery voltage: " + String(voltage));

  if(batteryLow()) {  Serial.println("Warning! Voltage Low!");  }
  delay(500);

}

// Read battery voltage on batteryPin 
//Can be used for waterDetect aswell
float batteryVoltage() {
  int sensorValue = analogRead(batteryPin); 
  float voltage = sensorValue * (5.0 / 1023.0);

  return(voltage);
}

//Chech if batteryVoltage is below threshold
//Can probably be used for waterDetect aswell with different thresholds
bool batteryLow() {
  float limit = 2.0;
  float voltage = batteryVoltage();
  return(voltage < limit);
}