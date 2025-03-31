#include <Arduino.h>
#include <SoftwareSerial.h>

// Create software serial object for SIM7670E
SoftwareSerial mySerial(5, 4); // RX:D5, TX:D4

void sendATCommand(String command, String label);
void updateSerial();

void setup()
{
  Serial.begin(9600); // Serial Monitor
  mySerial.begin(9600); // SIM Module

  Serial.println("Initializing...");
  delay(1000);

  sendATCommand("AT", "Test AT");
  sendATCommand("AT+CSQ", "Signal Quality");
  sendATCommand("AT+CCID", "SIM Card Info");
  sendATCommand("AT+CREG?", "Network Registration");
  sendATCommand("AT+SIMCOMATI", "Module Info");
}

void loop()
{
  updateSerial();
}

void sendATCommand(String command, String label)
{
  Serial.println("\nSending: " + command);
  mySerial.println(command);
  delay(500);

  if (mySerial.available()) {
    Serial.print(label + " Response: ");
    while (mySerial.available()) {
      Serial.write(mySerial.read());
    }
    Serial.println();
  } else {
    Serial.println(label + " Response: No response.");
  }
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read()); // Forward Serial Monitor input to SIM7670E
  }
  while (mySerial.available()) 
  {
    Serial.write(mySerial.read()); // Forward SIM7670E output to Serial Monitor
  }
}
