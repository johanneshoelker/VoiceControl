boolean mainlighton = LOW;

#define PIN_LED 2                                                  // Pin, an dem die LED angeschlossen ist.
#define PIN_BUTTON 3                                               // Pin, an dem der Taster angeschlossen ist.

boolean aLedEnabled = false;                                        // True, wenn die LED leuchtet, sonst false.
boolean aButtonPressed = false;                                     // True, wenn der Taster gedrÃ¼ckt wird, sonst false.

void setup()
{
  pinMode(PIN_LED, OUTPUT);                                         // Pin, an dem die LED angeschlossen ist, als Ausgang festlegen.
  pinMode(PIN_BUTTON, INPUT_PULLUP);                                // Pin, an dem der Taster angeschlossen ist, als Eingang mit aktiviertem Pull-Up-Widerstand festlegen.
}

void loop()
{
  if (digitalRead(PIN_BUTTON) == LOW) {                             // Wenn der Taster aktuell gedrÃ¼ckt wird, ...
    aButtonPressed = true;                                          // merke dir, dass der Taster gedrÃ¼ckt wurde, ...
    delay(10);                                                      // und warte 10 Millisekunden bis die Kontakte des Tasters vollstÃ¤ndig geschlossen sind.
  }

  if (digitalRead(PIN_BUTTON) == HIGH && aButtonPressed == true) {  // Wenn der Taster nicht gedrÃ¼ckt wird, aber zuvor gedrÃ¼ckt wurde ...
    aButtonPressed = false;                                         // vergesse, dass der Taster gedrÃ¼ckt wude.
    
    if (aLedEnabled == true) {                                      // Wenn die LED gerade leuchtet ...
      digitalWrite(PIN_LED, LOW);                                   // schalte die LED aus ...
      aLedEnabled = false;                                          // und merke dir, dass die LED gerade nicht leuchtet,
    } else {                                                        // sonst ...
      digitalWrite(PIN_LED, HIGH);                                  // schalte die LED ein ...
      aLedEnabled = true;                                           // und merke dir, dass die LED gerade leuchtet.
    }
  }
}
