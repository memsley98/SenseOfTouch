// Code Modified from: 
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   50

uint8_t pads[] = {3, 0, 6, 10};
uint8_t numberOfPads = sizeof(pads)/sizeof(uint8_t);

////////////////////////////////////////////////////////////////////////////
void takeAction(uint8_t pad) {
  Serial.print("PAD "); Serial.print(pad); Serial.print(" playing note: ");
  switch (pad) {
    case 3:
      Serial.println("C");
      CircuitPlayground.playTone(392, 100, false);
      CircuitPlayground.playTone(330, 100, false);
      CircuitPlayground.playTone(392, 100, false);
      CircuitPlayground.playTone(392, 100, false);
      CircuitPlayground.playTone(330, 100, false);
      CircuitPlayground.playTone(392, 100, false);
      break;

      // love pad
      //i love you you love me (barney)

    case 0:
      Serial.println("E");
      CircuitPlayground.playTone(110, 100, false);
      CircuitPlayground.playTone(98, 100, false);
      CircuitPlayground.playTone(87, 100, false);
      CircuitPlayground.playTone(82, 100, false);
      break;
      //sad pad 
      // sad written melody low octave
      
    case 6:
      Serial.println("A");
      CircuitPlayground.playTone(330, 100, false);
      CircuitPlayground.playTone(349, 100, false);
      CircuitPlayground.playTone(392, 100, false);
      CircuitPlayground.playTone(440, 100, false);
      break;

    // happy pad 
    //opposite of sad in high octave
    
    case 10:
      Serial.println("C");
      CircuitPlayground.playTone(62, 100, false);
      CircuitPlayground.playTone(62, 100, false);
      CircuitPlayground.playTone(62, 100, false);
      
      break;
      // angry pad 
      //angry melody
    default:
      Serial.println("THIS SHOULD NEVER HAPPEN.");
  }
}

////////////////////////////////////////////////////////////////////////////
boolean capButton(uint8_t pad) {
  // Check if capacitive touch exceeds threshold.
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;  
  } else {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////
void setup() {
  // Initialize serial.
  Serial.begin(9600); 
  
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();

}

////////////////////////////////////////////////////////////////////////////
void loop() {
  // Loop over every pad.
  for (int i=0; i<numberOfPads; i++) {
    
    // Check if pad is touched.
    if (capButton(pads[i])) {
      
      // Do something.
      takeAction(pads[i]);
    }
  }
}
