// BUGG ???: när man slår av toggle, men LED är på, fortsätter LED lysa.


// LIBRARIES
#include <Bounce2.h> //debounce library för digital buttons
// #include <MIDI.h> - if I want regular wired MIDI


//----- ANALOG POTS
// declare variables for reading analog pot pins
const int analogPotPins[] = {16, 17, 18, 19};
const int numberOfAnalogPots = 4;
int oldAnalogPotReading[numberOfAnalogPots];
int analogPotValue[numberOfAnalogPots];
int oldAnalogPotValue[numberOfAnalogPots];


//----- TOGGLE

// declare variables for reading toggle switch pins
const int digitalToggleSwitchPins[] = {5, 6, 7, 8};
const int numberOfToggleSwitches = 4;
bool toggleSwitchValue[] = {0, 0, 0, 0}; //actual value
bool oldToggleSwitchValue[] = {0, 0, 0, 0}; //actual value

// declare debounce for toggle switches
Bounce toggleDebounce0 = Bounce();
Bounce toggleDebounce1 = Bounce();
Bounce toggleDebounce2 = Bounce();
Bounce toggleDebounce3 = Bounce();


//----- STOMP SWITCHES

// declare variables for reading stomp switches
const int digitalStompSwitchPins[] = {11, 12, 14, 15}; // TO BE CHANGED
const int numberOfStompSwitches = 4;
bool stompSwitchPressed[] = {0, 0, 0, 0}; //is switch pressed?
bool oldStompSwitchPressed[] = {0, 0, 0, 0}; //OLD is switch pressed?
bool stompSwitchValue[]  = {0, 0, 0, 0} ; // does the program think it's pressed?
bool oldStompSwitchValue[]  = {0, 0, 0, 0} ; // OLD does the program think it's pressed?

//declare debounce for stomp switches
Bounce stompDebounce0 = Bounce();
Bounce stompDebounce1 = Bounce();
Bounce stompDebounce2 = Bounce();
Bounce stompDebounce3 = Bounce();


//----- LED
const int ledPin[] = {3, 4, 9, 10};
const int numberOfLeds = 4;
int ledBrightness[] = {0, 0, 0, 0};


//------------ SETUP ------------//

void setup() {

  //----- TOGGLE SWITCHES

  // init toggle switch pins
  for (int i = 0; i < numberOfToggleSwitches; i++) {
    pinMode(digitalToggleSwitchPins[i], INPUT_PULLUP);
  }

  //Setup debounce for toggle switches
  toggleDebounce0.attach(digitalToggleSwitchPins[0]);
  toggleDebounce0.interval(5); // interval in ms

  toggleDebounce1.attach(digitalToggleSwitchPins[1]);
  toggleDebounce1.interval(5); // interval in ms

  toggleDebounce2.attach(digitalToggleSwitchPins[2]);
  toggleDebounce2.interval(5); // interval in ms

  toggleDebounce3.attach(digitalToggleSwitchPins[3]);
  toggleDebounce3.interval(5); // interval in ms


  //----- LEDS
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], 0);
  }


  //-----  STOMP SWITCHES
  
  // init stomp switch pins
  for (int i = 0; i < numberOfStompSwitches; i++) {
    pinMode(digitalStompSwitchPins[i], INPUT_PULLUP);
  }

  //initiate debounce for stomp switches
  stompDebounce0.attach(digitalStompSwitchPins[0]);
  stompDebounce0.interval(5); // interval in ms

  stompDebounce1.attach(digitalStompSwitchPins[1]);
  stompDebounce1.interval(5); // interval in ms

  stompDebounce2.attach(digitalStompSwitchPins[2]);
  stompDebounce2.interval(5); // interval in ms

  stompDebounce3.attach(digitalStompSwitchPins[3]);
  stompDebounce3.interval(5); // interval in ms


  //initiate serial, for debug
  //Serial.begin(9600);
}



//------------ LOOP ------------//

void loop() {

  //----- READ PHYSICAL PINS
  ReadAnalogPots();
  ReadToggleSwitches();
  ReadStompSwitches();

  //----- BASIC FUNCTION FOR STOMP SWITCHES
  // To be deleted when I've written better functions

  for (int i = 0; i < numberOfStompSwitches; i++) {
    StompSwitchMode(i, i);
  }


  //----- DO STUFF
  // Eventually replaced by switch case for "menu"
   
  usbMidiTest();

  //----- WRITE PHYSICAL PINS

  for (int i = 0; i < numberOfLeds; i++) {
    LedBrightness(i, i);    
    LedControlledByStomp(i,i); //Hard coded relationship, not optimal?
    
    //LedWrite(i, i); // old function, digital write
  }


  //----- FINISH THIS ITERATION
  // Save this iteration's values, so that next iteration
  // can tell if something has changed
  EndSequence();

  delay(4);
}



//------------ EXTRA FUNCTIONS ------------//

// Save variables for next iteration
void EndSequence() {

  // STOMP SWITCHES

  for (int i = 0; i < numberOfStompSwitches; i++) {
    oldStompSwitchPressed[i] = stompSwitchPressed[i];
  }

  for (int i = 0; i < numberOfStompSwitches; i++) {
    oldStompSwitchValue[i] = stompSwitchValue[i];
  }

}




