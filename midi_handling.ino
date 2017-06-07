
//--- CC mode
// stomp skickar CC
// ratt skickar annan cc
// toggle är latch


// skulle man kunna göra det här snyggare genom att köra
//en funktion istället för globala variabler för så mkt?
// typ funktionen "vad är stompSwitchValue?". Det gör jag globalt nu.


void usbMidiTest() {
  // specify MIDI CC
  int usbMidiChannel = 1;
  int usbMidiStompCc[] {74, 75, 76, 77};
  int usbMidiPotCc[] {102, 103, 104, 105};

  // Send pot value as CC


  for (int i = 0; i < numberOfAnalogPots; i++) {

    if (analogPotValue[i] != oldAnalogPotValue[i]) {
      usbMIDI.sendControlChange(usbMidiPotCc[i], analogPotValue[i], usbMidiChannel); // CC nr, value, midichannel
      //MIDI.sendControlChange(usbMidiPotCc[i], analogPotValue[i], usbMidiChannel); // CC nr, value, midichannel
      oldAnalogPotValue[i] = analogPotValue[i];
    }
  }
  // send stomp swithc value as CC


  for (int i = 0; i < numberOfStompSwitches; i++) {
    if (stompSwitchValue[i] != oldStompSwitchValue[i]) {
      if (stompSwitchValue[i] == 1) {
        usbMIDI.sendControlChange(usbMidiStompCc[i], 127, usbMidiChannel); // CC nr, value, midichannel
        //MIDI.sendControlChange(usbMidiStompCc[i], 127, usbMidiChannel); // CC nr, value, midichannel
      }

      else {
        usbMIDI.sendControlChange(usbMidiStompCc[i], 0, usbMidiChannel); // CC nr, value, midichannel
        //MIDI.sendControlChange(usbMidiStompCc[i], 0, usbMidiChannel); // CC nr, value, midichannel
      }
    }
  }

}

