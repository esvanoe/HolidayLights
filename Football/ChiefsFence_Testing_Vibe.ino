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
#define PIXEL_COUNT 350
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

void setPixels(uint16_t start, uint16_t end, uint32_t color) {
  for (uint16_t i = start; i < end; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void colorFade(uint8_t reps, uint16_t wait) {
  for (uint8_t count = 0; count < reps; count++) {
    for (uint16_t bright = 10; bright < 101; bright += 2) {
      setPixels(0, strip.numPixels(), strip.Color(2.5 * bright, 0, 0));
      delay(wait);
    }
    for (uint16_t bright = 100; bright > 9; bright -= 2) {
      setPixels(0, strip.numPixels(), strip.Color(2.5 * bright, 0, 0));
      delay(wait);
    }
    for (uint16_t bright = 10; bright < 101; bright += 2) {
      setPixels(0, strip.numPixels(), strip.Color(2.5 * bright, 2.5 * bright, 2.5 * bright));
      delay(wait);
    }
    for (uint16_t bright = 100; bright > 9; bright -= 2) {
      setPixels(0, strip.numPixels(), strip.Color(2.5 * bright, 2.5 * bright, 2.5 * bright));
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
  long randNumbers[12];
  for (uint8_t f = 0; f < 201; f++) {
    for (int i = 0; i < 12; i++) {
      randNumbers[i] = random(i < 6 ? 0 : 176, i < 6 ? 175 : 350);
    }
    for (int i = 0; i < 6; i++) {
      strip.setPixelColor(randNumbers[i], color1);
      strip.setPixelColor(randNumbers[i + 6], color2);
    }
    strip.show();
    delay(wait);
    for (int i = 0; i < 12; i++) {
      strip.setPixelColor(randNumbers[i], strip.Color(0, 0, 0));
    }
    strip.show();
    delay(wait);
  }
}

void colorOff(uint16_t wait) {
  for(uint16_t f=0; f-1<strip.numPixels(); f++) {
    strip.setPixelColor(f, strip.Color(0, 0, 0));
    }
  strip.show();
  delay(wait);
}