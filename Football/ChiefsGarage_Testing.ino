/* ======================= includes ================================= */

#include "Particle.h"
#include "neopixel.h"

/* ======================= prototypes =============================== */

void colorFlash(uint8_t reps, uint16_t wait);
void colorWipe(uint16_t wait);
void colorOff(uint16_t wait);
void twinkleWhite(uint8_t wait, uint32_t color1, uint32_t color2);
long randN; 
long randN1;
long randN2;
long randN3; 
long randN4;
long randN5;
long randN6; 
long randN7;
long randN8;
long randN9; 
long randN10;
long randN11;

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
  for(uint8_t f=0; f<201; f++) {
    randN = random(0, 160);
    randN1 = random(161, 320);
    randN2 = random(0, 160);
    randN3 = random(161, 320);
    randN4 = random(0, 160);
    randN5 = random(161, 320);
    randN6 = random(0, 160);
    randN7 = random(161, 320);
    randN8 = random(0, 160);
    randN9 = random(161, 320);
    randN10 = random(0, 160);
    randN11 = random(161, 320);
    strip.setPixelColor(randN, color1);
    strip.setPixelColor(randN1, color1);
    strip.setPixelColor(randN2, color2);
    strip.setPixelColor(randN3, color2);
    strip.setPixelColor(randN4, color1);
    strip.setPixelColor(randN5, color1);
    strip.show();
    delay(wait);
    strip.setPixelColor(randN6, color1);
    strip.setPixelColor(randN7, color1);
    strip.setPixelColor(randN8, color2);
    strip.setPixelColor(randN9, color2);
    strip.setPixelColor(randN10, color1);
    strip.setPixelColor(randN11, color1);
    strip.setPixelColor(randN, strip.Color(0, 0, 0));
    strip.setPixelColor(randN1, strip.Color(0, 0, 0));
    strip.setPixelColor(randN2, strip.Color(0, 0, 0));
    strip.setPixelColor(randN3, strip.Color(0, 0, 0));
    strip.setPixelColor(randN4, strip.Color(0, 0, 0));
    strip.setPixelColor(randN5, strip.Color(0, 0, 0));
    strip.show();
    delay(wait);
    strip.setPixelColor(randN6, strip.Color(0, 0, 0));
    strip.setPixelColor(randN7, strip.Color(0, 0, 0));
    strip.setPixelColor(randN8, strip.Color(0, 0, 0));
    strip.setPixelColor(randN9, strip.Color(0, 0, 0));
    strip.setPixelColor(randN10, strip.Color(0, 0, 0));
    strip.setPixelColor(randN11, strip.Color(0, 0, 0));
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