//----- ANALOG POTS

void ReadAnalogPots() {
  for (int i = 0; i < numberOfAnalogPots; i++) {
    int localPot = (analogRead(analogPotPins[i]) / 4 + oldAnalogPotReading[i]) / 2;
    if (oldAnalogPotReading[i] != localPot) {
      Serial.println((String)"Pot " + (i + 1) + " : " + (localPot / 2));
      analogPotValue[i] = localPot / 2;
    }

    oldAnalogPotReading[i] = localPot;
  }
}


//----- TOGGLE SWITCHES

void ReadToggleSwitches() {

  // Update the Bounce instances :
  toggleDebounce0.update();
  toggleDebounce1.update();
  toggleDebounce2.update();
  toggleDebounce3.update();


  // SWITCH 1
  if (toggleDebounce0.read() == 1) {
    toggleSwitchValue[0] = true;
  } else {
    toggleSwitchValue[0] = false;
  }

  if (toggleSwitchValue[0] != oldToggleSwitchValue[0]) {

    Serial.println((String)"Switch 1: " + toggleSwitchValue[0]);
  }

  oldToggleSwitchValue[0] = toggleSwitchValue[0];


  // SWITCH 2
  if (toggleDebounce1.read() == 1) {
    toggleSwitchValue[1] = true;
  } else {
    toggleSwitchValue[1] = false;
  }

  if (toggleSwitchValue[1] != oldToggleSwitchValue[1]) {

    Serial.println((String)"Switch 2: " + toggleSwitchValue[1]);
  }

  oldToggleSwitchValue[1] = toggleSwitchValue[1];

  // SWITCH 3
  if (toggleDebounce2.read() == 1) {
    toggleSwitchValue[2] = true;
  } else {
    toggleSwitchValue[2] = false;
  }

  if (toggleSwitchValue[2] != oldToggleSwitchValue[2]) {

    Serial.println((String)"Switch 3: " + toggleSwitchValue[2]);
  }

  oldToggleSwitchValue[2] = toggleSwitchValue[2];

  // SWITCH 4
  if (toggleDebounce3.read() == 1) {
    toggleSwitchValue[3] = true;
  } else {
    toggleSwitchValue[3] = false;
  }

  if (toggleSwitchValue[3] != oldToggleSwitchValue[3]) {

    Serial.println((String)"Switch 4: " + toggleSwitchValue[3]);
  }

  oldToggleSwitchValue[3] = toggleSwitchValue[3];
}


//----- LEDS

void LedWrite() {
  for (int i = 0; i < numberOfLeds; i++) {
    analogWrite(ledPin[i], ledBrightness[i]);
  }
}


//----- STOMP SWITCHES

void ReadStompSwitches() {

  stompDebounce0.update();
  stompDebounce1.update();
  stompDebounce2.update();
  stompDebounce3.update();


  // STOMP SWITCH 1

  if (stompDebounce0.read() == 0) {
    stompSwitchPressed[0] = true;
  } else {
    stompSwitchPressed[0] = false;
  }

  if (stompSwitchPressed[0] != oldStompSwitchPressed[0]) {

    Serial.println((String)"StompSwitch 1: " + stompSwitchPressed[0]);
  }


  // STOMP SWITCH 2

  if (stompDebounce1.read() == 0) {
    stompSwitchPressed[1] = true;
  } else {
    stompSwitchPressed[1] = false;
  }

  if (stompSwitchPressed[1] != oldStompSwitchPressed[1]) {

    Serial.println((String)"StompSwitch 2: " + stompSwitchPressed[1]);
  }


  // STOMP SWITCH 3

  if (stompDebounce2.read() == 0) {
    stompSwitchPressed[2] = true;
  } else {
    stompSwitchPressed[2] = false;
  }

  if (stompSwitchPressed[2] != oldStompSwitchPressed[2]) {

    Serial.println((String)"StompSwitch 3: " + stompSwitchPressed[2]);
  }


  // STOMP SWITCH 4

  if (stompDebounce3.read() == 0  ) {
    stompSwitchPressed[3] = true;
  } else {
    stompSwitchPressed[3] = false;
  }

  if (stompSwitchPressed[3] != oldStompSwitchPressed[3]) {

    Serial.println((String)"StompSwitch 4: " + stompSwitchPressed[3]);
  }

}
