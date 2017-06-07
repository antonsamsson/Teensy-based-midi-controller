
// STOMP SWITCHES

void StompSwitchMode(int stompSwitch,int toggleSwitch) {

  bool isMomentan = toggleSwitchValue[toggleSwitch];

  if (!isMomentan) {
    if (stompSwitchPressed[stompSwitch] != oldStompSwitchPressed[stompSwitch] && stompSwitchPressed[stompSwitch] == 1) {
      stompSwitchValue[stompSwitch] = 1 - stompSwitchValue[stompSwitch]; 

      
      Serial.println((String)"StompSwitchVALUE " + stompSwitch + " : " + stompSwitchValue[stompSwitch]);
    }

  } else {
        if (stompSwitchPressed[stompSwitch] != oldStompSwitchPressed[stompSwitch]) {
          stompSwitchValue[stompSwitch] = stompSwitchPressed[stompSwitch];
    Serial.println((String)"StompSwitchMOMENTAN " + stompSwitch + " : " + stompSwitchValue[stompSwitch]);
        }
  }
}



//----- LEDS

void LedBrightness(int led, int pot) {
  ledBrightness[led] = analogPotValue[pot] * 2;

  if (ledBrightness[led] <= 1) {
    ledBrightness[led] = 1;
  }

}

// standardfunktion - ifall jag bara vill styra LED med stomp

void LedControlledByStomp(int led, int stomp) {

  if (stompSwitchValue[stomp] == 0) {
    analogWrite(ledPin[led], 0);
  } else {
    analogWrite(ledPin[led], ledBrightness[led]);
  }
}


//------ OLD LED
void LedOn(int led, int stomp) {
  //om toggle = 1 vill jag att led ska lysa, med ledbrightness styrka
  //om toggle = 0 vill jag att den ska vara släckt

  if (stompSwitchValue[stomp] == 0) {
    analogWrite(ledPin[led], 0);
  } else {
    analogWrite(ledPin[led], ledBrightness[led]);
  }

}





