/* 
This is a copy of my first fence code. THIS ONE IS FOR PLAYING/TESTING
*/ 

/* ======================= includes ================================= */
#include "Particle.h"
#include "neopixel.h"
/* ======================= functions =============================== */

void colorFade(uint8_t reps, uint16_t speed);
void colorSplit(uint16_t wait, uint32_t split1, uint32_t split2);
void colorOff(uint16_t wait);
void colorChase(uint8_t reps, uint16_t speed, uint32_t rabbit, uint32_t blanket);
void rgbTwinkle(uint8_t reps, uint16_t speed);
void twinkle(uint8_t wait, uint32_t color1);
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
long randN12;
long randN13; 
long randN14;
long randN15;
/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));


// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 350
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
  rgbTwinkle(20, 800); // Reps, Speed
  twinkle(35, white); // Speed, Color
  colorOff(50);
  rgbTwinkle(20, 800); // Reps, Speed
  colorChase(3, 5, blue, green);    // reps, speed, rabbit, blanket
  rgbTwinkle(15, 800); // Reps, Speed
  twinkle(35, white); // Speed, Color
  colorOff(50);
  colorFade(2, 15); //reps, speed
  twinkle(35, red); // Speed, Color
  colorOff(50);    // wait
  rgbTwinkle(20, 800); // Reps, Speed
  colorOff(50);
  colorSplit(100, blue, white); // wait, down, up
  colorOff(200);    // wait
  colorSplit(100, green, blue); // wait, down, up
  twinkle(35, blue); // Speed, Color)
  colorOff(50);
  colorFade(2, 15); //reps, speed
  colorOff(50);    // wait
  colorChase(3, 5, red, blue);    // reps, speed, rabbit, blanket
  twinkle(35, white); // Speed, Color
  colorOff(50);
  colorChase(3, 5, green, blue);    // reps, speed, rabbit, blanket
  twinkle(35, white); // Speed, Color
  colorOff(50);    // wait
  colorSplit(100, red, blue);   // wait, down, up
  colorOff(50);    // wait
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
void colorSplit(uint16_t wait, uint32_t split1, uint32_t split2) {
  uint16_t down=strip.numPixels()/2;
  uint16_t up=strip.numPixels()/2+1;
  while(down>=0 && up<=350) {
    strip.setPixelColor(up, split1);
    strip.setPixelColor(up+1, split1);
    strip.setPixelColor(down, split1);
    strip.setPixelColor(down-1, split1);
    strip.show();
    delay(wait);
    up+=4;
    down-=4;
  }
  down=strip.numPixels()/2;
  up=strip.numPixels()/2+1;
  while(down>=0 && up<=strip.numPixels()) {
    strip.setPixelColor(up+2, split2);
    strip.setPixelColor(up+3, split2);
    strip.setPixelColor(down-2, split2);
    strip.setPixelColor(down-3, split2);
    strip.show();
    delay(wait);
    up+=4;
    down-=4;
  }
}

void colorChase(uint8_t reps, uint16_t speed, uint32_t rabbit, uint32_t blanket) {
  for(uint8_t count=0; count<reps; count++) {    
    for(uint16_t i=0; i<strip.numPixels()+300; i++) {
      strip.setPixelColor(i, 0, 0, 250);
      if(i>2) {
        strip.setPixelColor(i-3, rabbit);
        }
      if(i>50) {
        strip.setPixelColor(i-47, rabbit);
        strip.setPixelColor(i-48, rabbit);
        strip.setPixelColor(i-49, rabbit);
        strip.setPixelColor(i-50, off);
      }
      if(i>100) {
        strip.setPixelColor(i-97, rabbit);
        strip.setPixelColor(i-98, rabbit);
        strip.setPixelColor(i-99, rabbit);
        strip.setPixelColor(i-100, off);
      }
      if(i>150) {
        strip.setPixelColor(i-147, rabbit);
        strip.setPixelColor(i-148, rabbit);
        strip.setPixelColor(i-149, rabbit);
        strip.setPixelColor(i-150, off);
      }
      if(i>200) {
        strip.setPixelColor(i-197, rabbit);
        strip.setPixelColor(i-198, rabbit);
        strip.setPixelColor(i-199, rabbit);
        strip.setPixelColor(i-200, off);
      }
      if(i>250) {
        strip.setPixelColor(i-247, rabbit);
        strip.setPixelColor(i-248, rabbit);
        strip.setPixelColor(i-249, rabbit);
        strip.setPixelColor(i-250, off);
      }
      if(i>300) {
        strip.setPixelColor(i-297, rabbit);
        strip.setPixelColor(i-298, rabbit);
        strip.setPixelColor(i-299, rabbit);
        strip.setPixelColor(i-300, blanket);
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
  for(uint8_t f=0; f<101; f++) {
    randN = random(0, 175);
    randN1 = random(176, 350);
    randN2 = random(0, 175);
    randN3 = random(176, 350);
    randN4 = random(0, 175);
    randN5 = random(176, 350);
    randN6 = random(0, 175);
    randN7 = random(176, 350);
    randN8 = random(0, 175);
    randN9 = random(176, 350);
    randN10 = random(0, 175);
    randN11 = random(176, 350);
    randN12 = random(0, 175);
    randN13 = random(176, 350);
    randN14 = random(0, 175);
    randN15 = random(176, 350);
    strip.setPixelColor(randN, color1);
    strip.setPixelColor(randN1, color1);
    strip.setPixelColor(randN2, color1);
    strip.setPixelColor(randN2, color1);
    strip.setPixelColor(randN4, color1);
    strip.setPixelColor(randN5, color1);
    strip.setPixelColor(randN6, color1);
    strip.setPixelColor(randN7, color1);
    strip.show();
    delay(wait);
    strip.setPixelColor(randN8, color1);
    strip.setPixelColor(randN9, color1);
    strip.setPixelColor(randN10, color1);
    strip.setPixelColor(randN11, color1);
    strip.setPixelColor(randN12, color1);
    strip.setPixelColor(randN13, color1);
    strip.setPixelColor(randN14, color1);
    strip.setPixelColor(randN15, color1);
    strip.setPixelColor(randN, off);
    strip.setPixelColor(randN1, off);
    strip.setPixelColor(randN2, off);
    strip.setPixelColor(randN3, off);
    strip.setPixelColor(randN4, off);
    strip.setPixelColor(randN5, off);
    strip.setPixelColor(randN6, off);
    strip.setPixelColor(randN7, off);
    strip.show();
    delay(wait);
    strip.setPixelColor(randN8, off);
    strip.setPixelColor(randN9, off);
    strip.setPixelColor(randN10, off);
    strip.setPixelColor(randN11, off);
    strip.setPixelColor(randN12, off);
    strip.setPixelColor(randN13, off);
    strip.setPixelColor(randN14, off);
    strip.setPixelColor(randN15, off);
    strip.show();    
    }
}
