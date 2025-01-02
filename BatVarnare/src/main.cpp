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


void setup() {
  // put your setup code here, to run once:
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Check water

  delay(20);

  //Check battery
  //Send sms if warning
  //Check if new incoming sms
  //Add new cintact if incoming sms

  delay(20);

}

bool batteryLow {
  /*
  If battery voltage is lower than 11 volts for over 3 minutes return true.
  Otherwise return false.
  If two or more? meassurments are over 11 volts in those three minutes reset counter to zero.
  */

  if(voltage <= 3){
    return true;
  }

return false; 
}