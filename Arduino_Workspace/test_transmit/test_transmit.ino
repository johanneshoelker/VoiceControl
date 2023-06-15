/*
  Example for different sending methods

  https://github.com/sui77/rc-switch/

*/

#include <RCSwitch.h>
RCSwitch sender = RCSwitch();

void setup() {
  Serial.begin(9600);
  sender.enableTransmit(3);  // An Pin 3

  sender.setProtocol(1);
  sender.setPulseLength(311);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {


      digitalWrite(LED_BUILTIN, HIGH);
      sender.sendTriState("F0F0FF0FFF0F");

      delay(1000);

      digitalWrite(LED_BUILTIN, LOW);
      sender.sendTriState("F0F0FF0FFFF0");

      delay(1000);
}
