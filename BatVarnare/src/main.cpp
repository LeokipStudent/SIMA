/*
  Project to send a warning if the boat is taking in water or the battery is dying.
  Warnings sent using sms
  1. Send sms
  2. Check water sensor
  3. Check battery voltage
  4. Integrate everything
  5. Add new phone number to the system via sms
  6. Status updates upon receiving sms

  Authors: Erik and Leonard
  Ändrad
*/






#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}