// "ATMEGA328" for the Board
// "DEBUG" if you just want to debug the code in the serial monitor

#define DEBUG 1 

/////////////////////////////////////////////
// LIBRARIES
// -- Defines the MIDI library -- //

#ifdef ATMEGA328
#include <MIDI.h> // by Francois Best
MIDI_CREATE_DEFAULT_INSTANCE();
#endif
// ---- //

/////////////////////////////////////////////
// BUTTONS
const int N_BUTTONS = 8; //*  total numbers of buttons
const int BUTTON_ARDUINO_PIN[N_BUTTONS] = {2,3,4,5,6,7,8,9}; //* pins of each button connected straight to the Arduino
int x =0;
const int buttonPin = 11; // button for up transpose
const int buttonPin2 = 12;// button for down transpose
int buttonState = 0;  
int buttonState2 = 0;
int buttonCState[N_BUTTONS] = {};        // stores the button current value
int buttonPState[N_BUTTONS] = {};        // stores the button previous value
//
//#define pin13 1 //* uncomment if you are using pin 13 (pin with led), or comment the line if not using
//byte pin13index = 13; //* put the index of the pin 13 of the buttonPin[] array if you are using, if not, comment

// debounce
unsigned long lastDebounceTime[N_BUTTONS] = {0};  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    //* the debounce time; increase if the output flickers


// MIDI
byte midiCh = 1; //* MIDI channel to be used
byte note = 48; //* Lowest note to be used (this corresponds to C4)
byte cc = 1; //* Lowest MIDI CC to be used
// SETUP
void setup() {

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);

  // Baud Rate
  // 31250 for MIDI class compliant | 115200 for Hairless MIDI
  Serial.begin(115200); //*

#ifdef DEBUG
Serial.println("Debug mode");
Serial.println();
#endif

  // Buttons
  for (int i = 0; i < N_BUTTONS; i++) {
    pinMode(BUTTON_ARDUINO_PIN[i], INPUT_PULLUP);
  }

#ifdef pin13 
pinMode(BUTTON_ARDUINO_PIN[pin13index], INPUT);
#endif

}

// LOOP
void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  if(buttonState == 1)
  {
    x++;
    delay(500);
  }
  else if(buttonState2 == 1)
  {
    x--;
    delay(500);
  }
  buttons();

}

/////////////////////////////////////////////
// BUTTONS
void buttons() {

  for (int i = 0; i < N_BUTTONS; i++) {

    buttonCState[i] = digitalRead(BUTTON_ARDUINO_PIN[i]);  // read pins from arduino

#ifdef pin13
if (i == pin13index) {
buttonCState[i] = !buttonCState[i]; // inverts the pin 13 because it has a pull down resistor instead of a pull up
}
#endif

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {

      if (buttonPState[i] != buttonCState[i]) {
        lastDebounceTime[i] = millis();

        if (buttonCState[i] == LOW) {

          
#ifdef ATMEGA328
switch(i){
  case 0:MIDI.sendNoteOn(note + (i+x), 127, midiCh);break; // note, velocity, channel;
  case 1:MIDI.sendNoteOn(note + (i+1+x), 127, midiCh);break;
  case 2:MIDI.sendNoteOn(note + (i+2+x), 127, midiCh);break;// note, velocity, channel
  case 3:MIDI.sendNoteOn(note + (i+2+x), 127, midiCh);break;
  case 4:MIDI.sendNoteOn(note + (i+3+x), 127, midiCh);break;
  case 5:MIDI.sendNoteOn(note + (i+4+x), 127, midiCh);break;
  case 6:MIDI.sendNoteOn(note + (i+5+x), 127, midiCh);break;
  case 7:MIDI.sendNoteOn(note + (i+5+x), 127, midiCh);break;
  default:MIDI.sendNoteOn(note + (i+x), 127, midiCh);break;
}



#elif DEBUG
Serial.print(i);
Serial.println(": button on");
#endif

        }
        else {

 //Sends the MIDI note OFF accordingly to the chosen board
#ifdef ATMEGA328
// use if using with ATmega328 (uno, mega, nano...)
switch(i){
  case 0:MIDI.sendNoteOn(note + (i+x), 0, midiCh);break; // note, velocity, channel;
  case 1:MIDI.sendNoteOn(note + (i+1+x), 0, midiCh);break;
  case 2:MIDI.sendNoteOn(note + (i+2+x), 0, midiCh);break;// note, velocity, channel
  case 3:MIDI.sendNoteOn(note + (i+2+x), 0, midiCh);break;
  case 4:MIDI.sendNoteOn(note + (i+3+x), 0, midiCh);break;
  case 5:MIDI.sendNoteOn(note + (i+4+x), 0, midiCh);break;
  case 6:MIDI.sendNoteOn(note + (i+5+x), 0, midiCh);break;
  case 7:MIDI.sendNoteOn(note + (i+5+x), 0, midiCh);break;
  default:MIDI.sendNoteOn(note + (i+x), 0, midiCh);break;
}




#elif DEBUG
Serial.print(i);
Serial.println(": button off");
#endif

        }
        buttonPState[i] = buttonCState[i];
      }
    }
  }
}
