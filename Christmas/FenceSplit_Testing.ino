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
#define PIXEL_COUNT 350
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2811

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(80);
}

void loop() {
  twinkle(25, strip.Color(250, 250, 250)); // Speed, Color
  rgbTwinkle(100, 500); // Reps, Speed
  colorFade(2, 10); //reps, speed
  colorOff(200);
  twinkle(25, strip.Color(250, 0, 0)); // Speed, Color
  colorOff(200);    // wait
  rgbTwinkle(100, 500); // Reps, Speed
  colorOff(200);
  colorSplit(100, strip.numPixels()/2, strip.numPixels()/2+1); // wait, down, up
  colorOff(200);    // wait
  colorSplit(100, strip.numPixels()/2, strip.numPixels()/2+1); // wait, down, up
  colorOff(200);
  twinkle(25, strip.Color(0, 0, 250)); // Speed, Color)
  colorFade(2, 10); //reps, speed
  colorOff(200);    // wait
  colorChase(3, 5);    // reps, speed
  colorOff(200);    // wait
  colorSplit(100, strip.numPixels()/2, strip.numPixels()/2+1);   // wait, down, up
  colorOff(200);    // wait
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
  while(down>=0 && up<=350) {
    strip.setPixelColor(up, strip.Color(0, 0, 250));
    strip.setPixelColor(up+1, strip.Color(0, 0, 250));
    strip.setPixelColor(down, strip.Color(0, 0, 250));
    strip.setPixelColor(down-1, strip.Color(0, 0, 250));
    strip.show();
    delay(wait);
    up+=4;
    down-=4;
  }
  down=strip.numPixels()/2;
  up=strip.numPixels()/2+1;
  while(down>=0 && up<=strip.numPixels()) {
    strip.setPixelColor(up+2, strip.Color(250, 250, 250));
    strip.setPixelColor(up+3, strip.Color(250, 250, 250));
    strip.setPixelColor(down-2, strip.Color(250, 250, 250));
    strip.setPixelColor(down-3, strip.Color(250, 250, 250));
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
        strip.setPixelColor(i-50, 0, 0, 0);
      }
      if(i>100) {
        strip.setPixelColor(i-97, 0, 0, 250);
        strip.setPixelColor(i-98, 0, 0, 250);
        strip.setPixelColor(i-99, 0, 0, 250);
        strip.setPixelColor(i-100, 0, 0, 0);
      }
      if(i>150) {
        strip.setPixelColor(i-147, 0, 0, 250);
        strip.setPixelColor(i-148, 0, 0, 250);
        strip.setPixelColor(i-149, 0, 0, 250);
        strip.setPixelColor(i-150, 0, 0, 0);
      }
      if(i>200) {
        strip.setPixelColor(i-197, 0, 0, 250);
        strip.setPixelColor(i-198, 0, 0, 250);
        strip.setPixelColor(i-199, 0, 0, 250);
        strip.setPixelColor(i-200, 0, 0, 0);
      }
      if(i>250) {
        strip.setPixelColor(i-247, 0, 0, 250);
        strip.setPixelColor(i-248, 0, 0, 250);
        strip.setPixelColor(i-249, 0, 0, 250);
        strip.setPixelColor(i-250, 0, 0, 0);
      }
      if(i>300) {
        strip.setPixelColor(i-297, 0, 0, 250);
        strip.setPixelColor(i-298, 0, 0, 250);
        strip.setPixelColor(i-299, 0, 0, 250);
        strip.setPixelColor(i-300, 250, 250, 250);
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
    strip.setPixelColor(randN, color1);
    strip.setPixelColor(randN1, color1);
    strip.setPixelColor(randN2, color1);
    strip.setPixelColor(randN2, color1);
    strip.setPixelColor(randN4, color1);
    strip.setPixelColor(randN5, color1);
    strip.show();
    delay(wait);
    strip.setPixelColor(randN6, color1);
    strip.setPixelColor(randN7, color1);
    strip.setPixelColor(randN8, color1);
    strip.setPixelColor(randN9, color1);
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
