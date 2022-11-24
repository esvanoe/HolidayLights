/* ======================= includes ================================= */

#include "Particle.h"
#include "neopixel.h"

/* ======================= functions =============================== */

void colorFade(uint8_t reps, uint16_t wait);
void colorSplit(uint16_t wait);
void colorOff(uint16_t wait);

/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 300
#define PIXEL_PIN D5
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(80);
}

void loop() {
  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.show();
  colorFade(3, 30); //reps, wait
  colorOff(200);
  colorSplit(50);   // wait
}

void colorFade(uint8_t reps, uint16_t wait) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint16_t bright=1; bright<100; bright+=1) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(2.5*bright, 0, 0));
      }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=100; bright>10; bright-=1) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(2.5*bright, 0, 0));
        }
        strip.show();
        delay(wait);
      }
    for(uint16_t bright=1; bright<100; bright+=1) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0, 2.5*bright, 0));
      }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=100; bright>10; bright-=1) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(0, 2.5*bright, 0));
        }
        strip.show();
        delay(wait);
      }
  }
}

// Fill the dots two after two with a color, wait (ms) after each one
void colorSplit uint16_t wait) {
  for(uint16_t i=PIXEL_COUNT/2+1; i<strip.numPixels(); i+=4) {
    for(uint16_t f=PIXEL_COUNT/2; i>0; i-=4) {
        strip.setPixelColor(i, strip.Color(0, 0, 250));
        strip.setPixelColor(i+1, strip.Color(0, 0, 250));
        strip.setPixelColor(f, strip.Color(0, 0, 250));
        strip.setPixelColor(f-1, strip.Color(0, 0, 250));
        strip.show();
        delay(wait);
        strip.setPixelColor(i, strip.Color(250, 250, 250));
        strip.setPixelColor(i+1, strip.Color(250, 250, 250));
        strip.setPixelColor(f, strip.Color(250, 250, 250));
        strip.setPixelColor(f-1, strip.Color(250, 250, 250));
        strip.show();
        delay(wait);
        }
    } 
}

void colorOff(uint16_t wait) {
  for(uint16_t f=0; f-1<strip.numPixels(); f++) {
    strip.setPixelColor(f, strip.Color(0, 0, 0));
    }
  strip.show();
  delay(wait);
}
