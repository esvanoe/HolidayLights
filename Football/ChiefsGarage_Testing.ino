/* ======================= includes ================================= */

#include "Particle.h"
#include "neopixel.h"

/* ======================= prototypes =============================== */

void colorFlash(uint8_t reps, uint16_t wait);
void colorWipe(uint16_t wait);
void colorOff(uint16_t wait);
void twinkleWhite(uint8_t wait, uint32_t color1, uint32_t color2);

/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));

// IMPORTANT: Set pixel COUNT, PIN and TYPE
//Order of WS2811  - R -> G -> B
#define PIXEL_COUNT 320
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(75);
  randomSeed(analogRead(0));
}

void loop() {
  colorFade(3, 50); //reps, wait
  colorOff(200);
  colorFlash(100);   // wait
  colorOff(100);
  colorFlash(100);   // wait
  twinkleWhite(5, strip.Color(250, 250, 250), strip.Color(250, 0, 0));  // wait
  colorOff(100);
  colorFlash(100);   // wait
  colorOff(100);
}

void colorFade(uint8_t reps, uint16_t wait) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint16_t bright=10; bright<101; bright+=2) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(2.5*bright, 0, 0));
      }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=100; bright>9; bright-=2) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(2.5*bright, 0, 0));
        }
        strip.show();
        delay(wait);
      }
    for(uint16_t bright=10; bright<101; bright+=2) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(2.5*bright, 2.5*bright, 2.5*bright));
      }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=100; bright>9; bright-=2) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(2.5*bright, 2.5*bright, 2.5*bright));
        }
        strip.show();
        delay(wait);
      }
  }
}

// Make every 6 out of 12 red, then flash white in the 6 between them.
void colorFlash(uint16_t wait) {
  for(uint16_t i=16; i<strip.numPixels(); i+=16) {
      for(uint8_t l=9; l<17; l++){
        strip.setPixelColor(i-l, strip.Color(200, 0, 0));
      }
    strip.show();
    delay(wait);
    }
  for (uint8_t j=1; j<10; j++){  
    for(uint16_t i=16; i<strip.numPixels(); i+=16) {
        for(uint8_t l=1; l<9; l++){
            strip.setPixelColor(i-l, strip.Color(200, 200, 200));
        }
    }
    strip.show();
    delay(800);
    for(uint16_t i=16; i<strip.numPixels(); i+=16) {
        for(uint8_t l=1; l<9; l++){
            strip.setPixelColor(i-l, strip.Color(0, 0, 0));
        }
    }
    strip.show();
    delay(800);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(200, 0, 0));
    }
  strip.show();
  delay(1000);
    }
   }

void twinkleWhite(uint8_t wait, uint32_t color1, uint32_t color2) {
  #define NUM_RANDOMS 12
  long randNumbers[NUM_RANDOMS];
  
  for(uint8_t f=0; f<201; f++) {
    // Generate all random numbers at once
    for(int i = 0; i < NUM_RANDOMS; i++) {
      // Alternate between first half (0-160) and second half (161-320)
      randNumbers[i] = random(i % 2 == 0 ? 0 : 161, i % 2 == 0 ? 160 : 320);
    }
    
    // First set of pixels (turn on)
    strip.setPixelColor(randNumbers[0], color1);
    strip.setPixelColor(randNumbers[1], color1);
    strip.setPixelColor(randNumbers[2], color2);
    strip.setPixelColor(randNumbers[3], color2);
    strip.setPixelColor(randNumbers[4], color1);
    strip.setPixelColor(randNumbers[5], color1);
    strip.show();
    delay(wait);
    
    // Second set of pixels (turn on) and turn off first set
    strip.setPixelColor(randNumbers[6], color1);
    strip.setPixelColor(randNumbers[7], color1);
    strip.setPixelColor(randNumbers[8], color2);
    strip.setPixelColor(randNumbers[9], color2);
    strip.setPixelColor(randNumbers[10], color1);
    strip.setPixelColor(randNumbers[11], color1);
    strip.setPixelColor(randNumbers[0], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[1], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[2], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[3], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[4], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[5], strip.Color(0, 0, 0));
    strip.show();
    delay(wait);
    
    // Turn off second set
    strip.setPixelColor(randNumbers[6], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[7], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[8], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[9], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[10], strip.Color(0, 0, 0));
    strip.setPixelColor(randNumbers[11], strip.Color(0, 0, 0));
    strip.show();    
  }
}

void colorOff(uint16_t wait) {
  for(uint16_t f=0; f-1<strip.numPixels(); f++) {
    strip.setPixelColor(f, strip.Color(0, 0, 0));
    }
  strip.show();
  delay(wait);
}