/* 
This is a copy of my first fence code. THIS ONE IS FOR PLAYING/TESTING
*/ 

/* ======================= includes ================================= */
#include "Particle.h"
#include "neopixel.h"
/* ======================= functions =============================== */

void colorFade(uint8_t reps, uint16_t speed);
void colorSplit(uint16_t wait);
void colorOff(uint16_t wait, uint16_t down, uint16_t up);
void colorChase(uint8_t reps, uint16_t speed);
void rgbTwinkle(uint8_t reps, uint16_t speed);
void twinkle(uint8_t wait, uint32_t color1);
/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));


// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 320
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

uint32_t red = strip.Color(250, 0, 0);
uint32_t green = strip.Color(0, 250, 0);
uint32_t blue = strip.Color(0, 0, 250);
uint32_t white = strip.Color(250, 250, 250);
uint32_t off = strip.Color(0, 0, 0);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(80);
}

void loop() {
  twinkle(50, white); // Speed, Color
  rgbTwinkle(25, 1000); // Reps, Speed
  twinkle(50, white); // Speed, Color
  colorFade(1, 10); //reps, speed
  colorOff(200);
  twinkle(25, red); // Speed, Color
  colorOff(200);    // wait
  rgbTwinkle(25, 1000); // Reps, Speed
  colorOff(250);
  colorSplit(100, strip.numPixels()/2, strip.numPixels()/2+1); // wait, down, up
  colorOff(250);    // wait
  colorSplit(100, strip.numPixels()/2, strip.numPixels()/2+1); // wait, down, up
  colorOff(250);
  twinkle(25, blue); // Speed, Color)
  colorFade(1, 10); //reps, speed
  colorOff(250);    // wait
  colorChase(3, 5);    // reps, speed
  colorOff(250);    // wait
  colorSplit(100, strip.numPixels()/2, strip.numPixels()/2+1);   // wait, down, up
  colorOff(200);    // wait
}

void rgbTwinkle(uint8_t reps, uint16_t speed) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint16_t i=0; i<strip.numPixels(); i+=3) {
      strip.setPixelColor(i, red);
      strip.setPixelColor(i+1, green);
      strip.setPixelColor(i+2, blue);
    }
    strip.show();
    delay(speed);
    for(uint16_t i=0; i<strip.numPixels(); i+=3) {
      strip.setPixelColor(i, green);
      strip.setPixelColor(i+1, blue);
      strip.setPixelColor(i+2, red);
    }
    strip.show();
    delay(speed);
    for(uint16_t i=0; i<strip.numPixels(); i+=3) {
      strip.setPixelColor(i, blue);
      strip.setPixelColor(i+1, red);
      strip.setPixelColor(i+2, green);
    }
    strip.show();
    delay(speed);
    }
 }


void colorFade(uint8_t reps, uint16_t speed) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint16_t bright=5; bright<250; bright+=5) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(bright, 0, 0));
      }
      strip.show();
      delay(speed);
    }
      for(uint16_t bright=250; bright>5; bright-=5) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(bright, 0, 0));
        }
        strip.show();
        delay(speed);
      }
    for(uint16_t bright=5; bright<250; bright+=5) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0, bright, 0));
      }
      strip.show();
      delay(speed);
    }
      for(uint16_t bright=250; bright>5; bright-=5) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(0, bright, 0));
        }
        strip.show();
        delay(speed);
      }
    for(uint16_t bright=1; bright<250; bright+=5) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0, 0, bright));
      }
      strip.show();
      delay(speed);
    }
      for(uint16_t bright=250; bright>10; bright-=5) {
        for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, strip.Color(0, 0, bright));
        }
        strip.show();
        delay(speed);
      }
  }
}

// Fill the dots two after two with a color, wait (ms) after each one
void colorSplit(uint16_t wait, uint16_t down, uint16_t up) {
  while(down>=0 && up<=320) {
    strip.setPixelColor(up, blue);
    strip.setPixelColor(up+1, blue);
    strip.setPixelColor(down, blue);
    strip.setPixelColor(down-1, blue);
    strip.show();
    delay(wait);
    up+=4;
    down-=4;
  }
  down=strip.numPixels()/2;
  up=strip.numPixels()/2+1;
  while(down>=0 && up<=strip.numPixels()) {
    strip.setPixelColor(up+2, white);
    strip.setPixelColor(up+3, white);
    strip.setPixelColor(down-2, white);
    strip.setPixelColor(down-3, white);
    strip.show();
    delay(wait);
    up+=4;
    down-=4;
  }
}

void colorChase(uint8_t reps, uint16_t speed) {
  for(uint8_t count=0; count<reps; count++) {    
    for(uint16_t i=0; i<strip.numPixels()+300; i++) {
      strip.setPixelColor(i, 0, 0, 250);
      if(i>2) {
        strip.setPixelColor(i-3, 0, 0, 0);
        }
      if(i>50) {
        strip.setPixelColor(i-47, 0, 0, 250);
        strip.setPixelColor(i-48, 0, 0, 250);
        strip.setPixelColor(i-49, 0, 0, 250);
        strip.setPixelColor(i-50, off);
      }
      if(i>100) {
        strip.setPixelColor(i-97, 0, 0, 250);
        strip.setPixelColor(i-98, 0, 0, 250);
        strip.setPixelColor(i-99, 0, 0, 250);
        strip.setPixelColor(i-100, off);
      }
      if(i>150) {
        strip.setPixelColor(i-147, 0, 0, 250);
        strip.setPixelColor(i-148, 0, 0, 250);
        strip.setPixelColor(i-149, 0, 0, 250);
        strip.setPixelColor(i-150, off);
      }
      if(i>200) {
        strip.setPixelColor(i-197, 0, 0, 250);
        strip.setPixelColor(i-198, 0, 0, 250);
        strip.setPixelColor(i-199, 0, 0, 250);
        strip.setPixelColor(i-200, off);
      }
      if(i>250) {
        strip.setPixelColor(i-247, 0, 0, 250);
        strip.setPixelColor(i-248, 0, 0, 250);
        strip.setPixelColor(i-249, 0, 0, 250);
        strip.setPixelColor(i-250, off);
      }
      if(i>300) {
        strip.setPixelColor(i-297, 0, 0, 250);
        strip.setPixelColor(i-298, 0, 0, 250);
        strip.setPixelColor(i-299, 0, 0, 250);
        strip.setPixelColor(i-300, white);
      }
    strip.show();
    delay(speed);
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

void twinkle(uint8_t wait, uint32_t color1) {
  #define NUM_RANDOMS 12
  long randNumbers[NUM_RANDOMS];
  
  for(uint8_t f = 0; f < 101; f++) {
    // Generate all random numbers at once
    for(int i = 0; i < NUM_RANDOMS; i++) {
      // Alternate between first and second half of the strip
      randNumbers[i] = random(i % 2 == 0 ? 0 : 161, i % 2 == 0 ? 160 : 320);
    }
    
    // First set of pixels (turn on)
    for(int i = 0; i < 6; i++) {
      strip.setPixelColor(randNumbers[i], color1);
    }
    strip.show();
    delay(wait);
    
    // Second set of pixels (turn on) and turn off first set
    for(int i = 6; i < NUM_RANDOMS; i++) {
      strip.setPixelColor(randNumbers[i], color1);
    }
    for(int i = 0; i < 6; i++) {
      strip.setPixelColor(randNumbers[i], off);
    }
    strip.show();
    delay(wait);
    
    // Turn off second set
    for(int i = 6; i < NUM_RANDOMS; i++) {
      strip.setPixelColor(randNumbers[i], off);
    }
    strip.show();
  }
}
