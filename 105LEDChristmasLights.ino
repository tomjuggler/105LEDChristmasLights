//works with ChristmasLightController Processing code

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 105
#define BRIGHTNESS  20 // keep this low or blow up the Arduino - can go up to 255!!!!


// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

char inChar = 'f';

const int buttonPin = 12;
int outPin = 11;
int buttonState = 0;




#define FRAMES_PER_SECOND  120

unsigned long previousMillis = 0; 
const long interval = 20000;

void setup() {
  delay(3000);//powerup safety delay
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  Serial.begin(9600);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin, HIGH); //connect to buttonPin for switch!

  FastLED.showColor(CRGB::Black);

  
}

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns



void loop() {
 
  
  if (inChar == 'a') {
    previousMillis = millis();
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
      leds[i] = CRGB::Black;
      FastLED.show();
    }
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
      FastLED.show();
    }
  } else if (inChar == 's') {
    previousMillis = millis();
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
      leds[i] = CRGB::Black;
      FastLED.show();
    }
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
      FastLED.show();
    }
  } else if (inChar == 'd') {
    previousMillis = millis();
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
      leds[i] = CRGB::Black;
      FastLED.show();
    }
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Green;
      FastLED.show();
    }
  } else if (inChar == 'w') {
    previousMillis = millis();
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
      leds[i] = CRGB::Black;
      FastLED.show();
    }
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Yellow;
      FastLED.show();
    }
  } else if (inChar == 'e') {
    previousMillis = millis();
  }
  else if (inChar == 'f') { //default 
    // Call the current pattern function once, updating the 'leds' array
    gPatterns[gCurrentPatternNumber]();

    // send the 'leds' array out to the actual LED strip
    FastLED.show();
    // insert a delay to keep the framerate modest
    FastLED.delay(1000 / FRAMES_PER_SECOND);

    // do some periodic updates
    EVERY_N_MILLISECONDS( 20 ) {
      gHue++;  // slowly cycle the "base color" through the rainbow
    }
    EVERY_N_SECONDS( 20 ) {
      nextPattern();  // change patterns periodically
    }
  }
    
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    inChar = 'f'; //set back to default
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    inChar = (char)Serial.read();


  }
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void rainbow()
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS - 1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for ( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for ( int i = 0; i < 8; i++) {
    leds[beatsin16( i + 7, 0, NUM_LEDS - 1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
