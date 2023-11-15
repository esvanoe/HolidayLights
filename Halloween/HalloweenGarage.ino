/* ======================= includes =============================== */

#include "Particle.h"
#include "neopixel.h"

/* ======================= prototypes =============================== */

void colorFade(uint8_t reps, uint16_t wait);
void colorWipe(uint16_t wait);
void colorOff(uint16_t wait);
void slowColor(uint8_t wait, uint32_t color);


SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 320
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(75);
}

void loop() {
  colorFade(1, 50); //reps, wait
  slowColor(50, strip.Color(2.5, 0.5, 0.1));
  colorFade(1, 50); //reps, wait
  slowColor(50, strip.Color(2.5, 0, 2.5));
  colorFade(1, 50); //reps, wait
  slowColor(50, strip.Color(0, 2.5, 0));
  colorFade(1, 50); //reps, wait
  colorOff(200);
  colorWipe(100);   // wait
  colorFade(1, 50); //reps, wait
  colorOff(100);
  colorWipe(30);   // wait
  colorFade(1, 50); //reps, wait
  colorOff(100);
  colorWipe(100);   // wait
  colorOff(100);
}

void colorFade(uint8_t reps, uint16_t wait) {
  for(uint8_t count=0; count<reps; count++) {
    // Orange Light Section
    for(uint16_t bright=4; bright<91; bright+=2) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(2.5*bright, 0.5*bright, 0.1*bright));
        }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=90; bright>3; bright-=2) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(2.5*bright, 0.5*bright, 0.1*bright));
          }
        strip.show();
        delay(wait);
      }
    // Purple Light Section
    for(uint16_t bright=4; bright<91; bright+=2) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(2*bright, 0, 2*bright));
        }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=90; bright>3; bright-=2) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(2*bright, 0, 2*bright));
          }
        strip.show();
        delay(wait);
      }
    // Red Light Section
    for(uint16_t bright=4; bright<91; bright+=2) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(2*bright, 0, 0));
        }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=90; bright>3; bright-=2) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(2*bright, 0, 0));
          }
        strip.show();
        delay(wait);
      }
    // Green Light Section
    for(uint16_t bright=4; bright<91; bright+=2) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0, 2*bright, 0));
        }
      strip.show();
      delay(wait);
    }
      for(uint16_t bright=90; bright>3; bright-=2) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(0, 2*bright, 0));
          }
        strip.show();
        delay(wait);
      }
  }
}


void slowColor(uint8_t wait, uint32_t color) {
  for(uint16_t bright=1; bright<51; bright+=1) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, color*bright);
      }
    strip.show();
    delay(wait);
    }
  delay(25000);
    for(uint16_t bright=50; bright>0; bright-=1) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, color*bright);
        }
      strip.show();
      delay(wait);
      }
  }
// Fill the dots one after the other with a color, wait (ms) after each one
void colorWipe(uint16_t wait) {
  for(uint16_t i=3; i<strip.numPixels(); i+=4) {
    strip.setPixelColor(i-3, strip.Color(250, 50, 10));
    strip.show();
    delay(wait);
    strip.setPixelColor(i-1, strip.Color(10, 255, 0));
    strip.show();
    delay(wait);
    }
  for(uint16_t i=3; i<strip.numPixels(); i+=4) {
    strip.setPixelColor(i-2, strip.Color(10, 255, 0));
    strip.show();
    delay(wait);
    strip.setPixelColor(i, strip.Color(250, 50, 10));
    strip.show();
    delay(wait);
    }
  strip.show();
  delay(5000);
}

void colorOff(uint16_t wait) {
  for(uint16_t f=0; f-1<strip.numPixels(); f++) {
    strip.setPixelColor(f, strip.Color(0, 0, 0));
  }
  strip.show();
  delay(wait);
}