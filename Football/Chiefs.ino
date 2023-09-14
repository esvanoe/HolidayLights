/**
 * Runs 300 lights in a Purple and Orange fading and chasing pattern
 */

/* ======================= includes ================================= */

#include "Particle.h"
#include "neopixel.h"

/* ======================= prototypes =============================== */

void colorFade(uint8_t reps, uint16_t wait);
void colorWipe(uint16_t wait);
void colorOff(uint16_t wait);

/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 350
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2811
//Order of WS2811  - R -> G -> B


Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.setBrightness(75);
  strip.show();


//  colorFade(3, 50); //reps, wait
  colorOff(200);
  colorWipe(100);   // wait
  colorOff(100);
  colorWipe(100);   // wait
  colorOff(100);
  colorWipe(100);   // wait

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


// Fill the dots one after the other with a color, wait (ms) after each one
void colorWipe(uint16_t wait) {
  for(uint16_t i=12; i<strip.numPixels(); i+=12) {
    strip.setPixelColor(i-12, strip.Color(200, 0, 0));
    strip.setPixelColor(i-11, strip.Color(200, 0, 0));
    strip.setPixelColor(i-10, strip.Color(200, 0, 0));
    strip.setPixelColor(i-9, strip.Color(200, 0, 0));
    strip.setPixelColor(i-8, strip.Color(200, 0, 0));
    strip.setPixelColor(i-7, strip.Color(200, 0, 0));
    strip.show();
    delay(wait);
    }
  for(uint16_t i=12; i<strip.numPixels(); i+=12) {
    strip.setPixelColor(i-6, strip.Color(200, 200, 200));
    strip.setPixelColor(i-5, strip.Color(200, 200, 200));
    strip.setPixelColor(i-4, strip.Color(200, 200, 200));
    strip.setPixelColor(i-3, strip.Color(200, 200, 200));
    strip.setPixelColor(i-2, strip.Color(200, 200, 200));
    strip.setPixelColor(i-1, strip.Color(200, 200, 200));
  }
  strip.show();
  delay(500);
  //}
  for(uint16_t i=12; i<strip.numPixels(); i+=12) {
    strip.setPixelColor(i-6, strip.Color(0, 0, 0));
    strip.setPixelColor(i-5, strip.Color(0, 0, 0));
    strip.setPixelColor(i-4, strip.Color(0, 0, 0));
    strip.setPixelColor(i-3, strip.Color(0, 0, 0));
    strip.setPixelColor(i-2, strip.Color(0, 0, 0));
    strip.setPixelColor(i-1, strip.Color(0, 0, 0));
  }
  strip.show();
  delay(500);
//  }
  for(uint16_t i=12; i<strip.numPixels(); i+=12) {
    strip.setPixelColor(i-6, strip.Color(200, 200, 200));
    strip.setPixelColor(i-5, strip.Color(200, 200, 200));
    strip.setPixelColor(i-4, strip.Color(200, 200, 200));
    strip.setPixelColor(i-3, strip.Color(200, 200, 200));
    strip.setPixelColor(i-2, strip.Color(200, 200, 200));
    strip.setPixelColor(i-1, strip.Color(200, 200, 200));
    }
  strip.show();
  delay(500);
  //}
  for(uint16_t i=12; i<strip.numPixels(); i+=12) {
    strip.setPixelColor(i-6, strip.Color(0, 0, 0));
    strip.setPixelColor(i-5, strip.Color(0, 0, 0));
    strip.setPixelColor(i-4, strip.Color(0, 0, 0));
    strip.setPixelColor(i-3, strip.Color(0, 0, 0));
    strip.setPixelColor(i-2, strip.Color(0, 0, 0));
    strip.setPixelColor(i-1, strip.Color(0, 0, 0));
    }
  strip.show();
  delay(500);
  //}
  for(uint16_t i=12; i<strip.numPixels(); i+=12) {
    strip.setPixelColor(i-6, strip.Color(200, 200, 200));
    strip.setPixelColor(i-5, strip.Color(200, 200, 200));
    strip.setPixelColor(i-4, strip.Color(200, 200, 200));
    strip.setPixelColor(i-3, strip.Color(200, 200, 200));
    strip.setPixelColor(i-2, strip.Color(200, 200, 200));
    strip.setPixelColor(i-1, strip.Color(200, 200, 200));
    }
  strip.show();
  delay(3000);
}

void colorOff(uint16_t wait) {
  for(uint16_t f=0; f-1<strip.numPixels(); f++) {
    strip.setPixelColor(f, strip.Color(0, 0, 0));
    }
  strip.show();
  delay(wait);
}