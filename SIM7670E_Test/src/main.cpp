/*
  Code to test the SIM7670E module
  Basic Serial Test commands and SMS Test
  
*/

#include <Arduino.h>
#include <string.h>
#include <SoftwareSerial.h>

SoftwareSerial SIM7670(5, 4); //RX:D4, TX:D5


void setup() {
  SIM7670.begin(9600);
  Serial.begin(9600);
  delay(3000);
  
  String temp;
  String number = "+46704416636";
  String message = "Hej Varlden!";


  //Uncomment to send sms
  //sendSMS(number, message);

  temp = SIM7670.println("AT"); //Test
  delay(200);
  Serial.println("\nTest info:");
  Serial.println(temp);
  delay(100);
  
  temp = SIM7670.println("AT+SIMCOMATI"); //Query module info
  delay(200);
  Serial.println("\nModule info:");
  Serial.println(temp);
  delay(100);
  
  temp = SIM7670.println("AT+CSQ"); //Query signal strength info
  delay(200);
  Serial.println("\nSignal strength: ");
  Serial.println(temp);
  delay(100);

  temp = SIM7670.println("AT+CPIN?"); //SIM info
  delay(200);
  Serial.println("\nSIM info: ");
  Serial.println(temp);
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
}




//This function should be able to return true or false 
//depending on if the sms was sent succesfully or not


bool sendSMS(String number, String message) {

SIM7670.println("AT+CMGF=1"); // Set to text mode

delay(100);

SIM7670.println("AT+CMGS=\"" + number + "\""); // Set number to send SMS

delay(100);

SIM7670.println(message + "\r"); // Send message

delay(100);

SIM7670.println((char)26); // Send CTRL+Z to end SMS

delay(1000);

  return true;
}