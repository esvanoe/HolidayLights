/* ======================= includes ================================= */

#include "Particle.h"
#include "neopixel.h"

/* ======================= functions =============================== */

void colorFade(uint8_t reps, uint16_t wait);
void twoTwo(uint16_t wait);
void colorOff(uint16_t wait);
void rgbTwinkle(uint8_t reps, uint16_t speed);

/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 300
#define PIXEL_PIN D5
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  strip.setBrightness(95);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  rgbTwinkle(20, 800); // Reps, Speed
  colorFade(3, 30); //reps, wait
  twoTwo(40);   // wait
}

void rgbTwinkle(uint8_t reps, uint16_t speed) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint16_t i=0; i<strip.numPixels(); i+=3) {
      strip.setPixelColor(i, 255, 0, 0);
      strip.setPixelColor(i+1, 0, 255, 0);
      strip.setPixelColor(i+2, 0, 0, 255);
    }
    strip.show();
    delay(speed);
    for(uint16_t i=0; i<strip.numPixels(); i+=3) {
      strip.setPixelColor(i, 0, 255, 0);
      strip.setPixelColor(i+1, 0, 0, 255);
      strip.setPixelColor(i+2, 255, 0, 0);
    }
    strip.show();
    delay(speed);
    for(uint16_t i=0; i<strip.numPixels(); i+=3) {
      strip.setPixelColor(i, 0, 0, 255);
      strip.setPixelColor(i+1, 255, 0, 0);
      strip.setPixelColor(i+2, 0, 255, 0);
    }
    strip.show();
    delay(speed);
    }
  }

void colorFade(uint8_t reps, uint16_t wait) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint16_t bright=10; bright<250; bright+=5) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(bright, 0, 0));
      }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=250; bright>10; bright-=5) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(bright, 0, 0));
        }
        strip.show();
        delay(wait);
      }
    for(uint16_t bright=10; bright<250; bright+=5) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0, bright, 0));
      }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=250; bright>10; bright-=5) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(0, bright, 0));
        }
        strip.show();
        delay(wait);
      }
  }
}

// Fill the dots two after two with a color, wait (ms) after each one
void twoTwo(uint16_t wait) {
  for(uint16_t i=3; i<strip.numPixels(); i+=4) {
    strip.setPixelColor(i-3, strip.Color(0, 0, 250));
    strip.setPixelColor(i-2, strip.Color(0, 0, 250));
    strip.show();
    delay(wait);
    strip.setPixelColor(i-1, strip.Color(250, 250, 250));
    strip.setPixelColor(i, strip.Color(250, 250, 250));
    strip.show();
    delay(wait);
    }
  for(uint8_t reps=0; reps<20; reps++) {
    for(uint16_t i=3; i<strip.numPixels(); i+=4) {
      strip.setPixelColor(i-1, strip.Color(250, 250, 250));
      strip.setPixelColor(i, strip.Color(250, 250, 250));
      strip.setPixelColor(i-3, strip.Color(0, 0, 250));
      strip.setPixelColor(i-2, strip.Color(0, 0, 250));
      strip.show();
      delay(100);
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
