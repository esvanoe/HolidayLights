/**
 * Runs 300 lights in a Purple and Orange fading and chasing pattern
 * Trying to move colors and other vars into loop instead of functions to add versatility.
 */

/* ======================= includes ================================= */

#include "Particle.h"
#include "neopixel.h"

/* ======================= prototypes =============================== */

void colorFade(uint8_t reps, uint16_t wait);
void colorChase(uint16_t wait);
void colorOff(uint16_t wait);

/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 50
#define PIXEL_PIN D5
#define PIXEL_TYPE WS2811
#define PIXEL_COUNT2 50
#define PIXEL_PIN2 D6

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
Adafruit_NeoPixel strip2(PIXEL_COUNT2, PIXEL_PIN2, PIXEL_TYPE);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip2.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip2.show();
  strip.setBrightness(70);
  strip2.setBrightness(70);
}

void loop() {
/**
  colorFade(1, 30, strip.Color(1, 2.5, 0)); //reps, wait
  colorFade(1, 30, strip.Color(0, 1.5, 2.5)); //reps, wait
  colorFade(1, 30, strip.Color(2.5, 0, 0)); //reps, wait
  colorFade(1, 30, strip.Color(1, 2.5, 0)); //reps, wait
  colorFade(1, 30, strip.Color(0, 1.5, 2.5)); //reps, wait
  colorFade(1, 30, strip.Color(2.5, 0, 0)); //reps, wait
  colorFade(1, 30, strip.Color(1, 2.5, 0)); //reps, wait
  colorFade(1, 30, strip.Color(0, 1.5, 2.5)); //reps, wait
  colorFade(1, 30, strip.Color(2.5, 0, 0)); //reps, wait
**/ 

  colorChase(100);   // wait
  colorOff(1000);
//  colorChase(50);   // wait
//  colorOff(100);
//  colorChase(50);   // wait

//  colorOff(50);
  
}

// Fill the dots one after the other with a color, wait (ms) after each one
void colorChase(uint16_t wait) {
  for(uint16_t i=2; i<strip.numPixels(); i+=4) {
    strip.setPixelColor(i, strip.Color(245, 0, 0));
    strip.show();
    delay(wait);
    strip2.setPixelColor(i-2, strip.Color(102, 255, 0));
    strip2.show();
    delay(wait);
  }
}

void colorOff(uint16_t wait) {
  for(uint16_t f=0; f-1<strip.numPixels(); f++) {
    strip.setPixelColor(f, strip.Color(0, 0, 0));
    strip2.setPixelColor(f, strip.Color(0, 0, 0));
  }
  strip.show();
  strip2.show();
  delay(wait);
}

void colorFade(uint8_t reps, uint16_t wait, uint32_t c) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint8_t bright=1; bright<100; bright+=1) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c*bright);
      }
      strip.show();
      delay(wait);
    }
      for(uint8_t bright=100; bright>10; bright-=1) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, c*bright);
        }
        strip.show();
        delay(wait);
      }
  }
}
