//works with ChristmasLightController Processing code

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 105
#define BRIGHTNESS  20 //change to 200 for shows!!!!


// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

char inChar;

const int buttonPin = 12;  
int outPin = 11;
int buttonState = 0; 

void setup() { 
  delay(3000);//powerup safety delay
	FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
FastLED.setBrightness(  BRIGHTNESS );
Serial.begin(9600); 
 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin, HIGH); //connect to buttonPin for switch!

  FastLED.showColor(CRGB::Black);
}

void loop() { 
  
//  // read the state of the pushbutton value:
//  buttonState = digitalRead(buttonPin);
//
//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (buttonState == HIGH) {
////    Serial.println("HIGH");
//    
//       // First slide the led in one direction
//  for(int i = 0; i < NUM_LEDS; i++) {
//    // Set the i'th led to red 
//    leds[i] = CRGB::Red;
//    // Show the leds
//    FastLED.show();
//    // now that we've shown the leds, reset the i'th led to black
////    leds[i] = CRGB::Black;
//    // Wait a little bit before we loop around and do it again
////    FastLED.delay(30);
//  }
//   // Now go in the other direction.  
//  for(int i = NUM_LEDS-1; i >= 0; i--) {
//    // Set the i'th led to red 
//    leds[i] = CRGB::Black;
//    // Show the leds
//    FastLED.show();
//    // now that we've shown the leds, reset the i'th led to black
////    leds[i] = CRGB::Black;
//    // Wait a little bit before we loop around and do it again
////    FastLED.delay(30);
//  }
//  
//    }
//   else {
//    Serial.println("LOW");
    /*
    // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB::Blue;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
//    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
//    FastLED.delay(30);
  }
   // Now go in the other direction.  
  for(int i = NUM_LEDS-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CRGB::Black;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
//    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
//    FastLED.delay(30);
  }
  */
// }
  
//  FastLED.showColor(CRGB::Green);
//  FastLED.showColor(CRGB::Black);

  if(inChar=='a'){
//    FastLED.showColor(CRGB::Green);
// First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB::Blue;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
//    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
//    FastLED.delay(30);
  }
    }else if(inChar=='s'){
//      FastLED.showColor(CRGB::Green);
   // Now go in the other direction.  
  for(int i = NUM_LEDS-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CRGB::Red;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
//    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
//    FastLED.delay(30);
  }
    }else if(inChar=='d'){
  //    FastLED.showColor(CRGB::Green);
// First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CRGB::Green;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
//    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
//    FastLED.delay(30);
  }
     
    } else if(inChar=='w'){
      for(int i = NUM_LEDS-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CRGB::Yellow;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
//    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
//    FastLED.delay(30);
  }
     
    }else if(inChar=='e'){
  
    }
//	// First slide the led in one direction
//	for(int i = 0; i < NUM_LEDS; i++) {
//		// Set the i'th led to red 
//		leds[i] = CRGB::Cyan;
//		// Show the leds
//		FastLED.show();
//		// now that we've shown the leds, reset the i'th led to black
////		leds[i] = CRGB::Black;
//		// Wait a little bit before we loop around and do it again
//		FastLED.delay(30);
//	}

	// Now go in the other direction.  
//	for(int i = NUM_LEDS-1; i >= 0; i--) {
//		// Set the i'th led to red 
//		leds[i] = CRGB::Magenta;
//		// Show the leds
//		FastLED.show();
//		// now that we've shown the leds, reset the i'th led to black
////		leds[i] = CRGB::Black;
//		// Wait a little bit before we loop around and do it again
//		FastLED.delay(30);
//	}

}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    inChar = (char)Serial.read();
   
    
  }
}
