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
void KITT(uint8_t reps, uint16_t segLength, uint8_t wait, uint32_t color1);
void meteorChaseBlue();
void meteorChaseRed();
void meteorChaseWhite();

/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));


// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 350
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2811
#define NUM_RANDOMS 16

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

uint32_t red = strip.Color(250, 0, 0);
uint32_t green = strip.Color(0, 250, 0);
uint32_t blue = strip.Color(0, 0, 250);
uint32_t white = strip.Color(250, 250, 250);
uint32_t off = strip.Color(0, 0, 0);
uint16_t half=strip.numPixels()/2;
uint16_t length=strip.numPixels();

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(80);
}

void loop() {

  meteorChaseBlue();
  meteorChaseBlue();
  meteorChaseBlue();
  meteorChaseRed();
  meteorChaseRed();
  meteorChaseRed();
  meteorChaseWhite();
  meteorChaseWhite();
  meteorChaseWhite();
  KITT(3, 30, 30, blue); // Reps, segLength, Speed, Color
  colorOff(50);
  KITT(3, 30, 30, red); // Reps, segLength, Speed, Color
  colorOff(50);
  rgbTwinkle(10, 800); // Reps, Speed
  twinkle(35, white); // Speed, Color
  colorOff(50);
  rgbTwinkle(10, 800); // Reps, Speed
  colorChase(3, 5, blue, green);    // reps, speed, rabbit, blanket
  twinkle(35, white); // Speed, Color
  colorOff(50);
  colorFade(2, 15); //reps, speed
  twinkle(35, red); // Speed, Color
  KITT(3, 30, 30, green); // Reps, segLength, Speed, Color
  colorOff(50);    // wait
  meteorChaseBlue();
  meteorChaseBlue();
  meteorChaseBlue();
  meteorChaseRed();
  meteorChaseRed();
  meteorChaseRed();
  meteorChaseWhite();
  meteorChaseWhite();
  meteorChaseWhite();
  rgbTwinkle(10, 800); // Reps, Speed
  colorOff(50);
  colorSplit(100, blue, white); // wait, down, up
  colorOff(200);    // wait
  colorSplit(100, green, blue); // wait, down, up
  twinkle(35, blue); // Speed, Color)
  KITT(3, 30, 30, blue); // Reps, segLength, Speed, Color
  colorOff(50);
  colorOff(50);
  rgbTwinkle(10, 800); // Reps, Speed
  colorOff(50);
  colorSplit(100, red, green); // wait, down, up
  twinkle(35, blue); // Speed, Color)
  colorOff(50);
  rgbTwinkle(10, 800); // Reps, Speed  
  colorFade(2, 15); //reps, speed
  colorOff(50);    // wait
  KITT(3, 30, 30, green); // Reps, segLength, Speed, Color
  colorOff(50);
  meteorChaseBlue();
  meteorChaseBlue();
  meteorChaseBlue();
  meteorChaseRed();
  meteorChaseRed();
  meteorChaseRed();
  meteorChaseWhite();
  meteorChaseWhite();
  meteorChaseWhite();
  colorChase(3, 5, red, blue);    // reps, speed, rabbit, blanket
  twinkle(35, white); // Speed, Color
  colorOff(50);
  colorOff(50);
  colorChase(3, 5, green, blue);    // reps, speed, rabbit, blanket
  twinkle(35, white); // Speed, Color
  colorOff(50);    // wait
  KITT(3, 30, 30, red); // Reps, segLength, Speed, Color
  colorOff(50);
  colorSplit(100, red, blue);   // wait, down, up
  colorOff(50);    // wait
}

void rgbTwinkle(uint8_t reps, uint16_t speed) {
  for(uint8_t count=0; count<reps; count++) {
    for(uint16_t i=0; i<length; i+=3) {
      strip.setPixelColor(i, red);
      strip.setPixelColor(i+1, green);
      strip.setPixelColor(i+2, blue);
    }
    strip.show();
    delay(speed);
    for(uint16_t i=0; i<length; i+=3) {
      strip.setPixelColor(i, green);
      strip.setPixelColor(i+1, blue);
      strip.setPixelColor(i+2, red);
    }
    strip.show();
    delay(speed);
    for(uint16_t i=0; i<length; i+=3) {
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
      for(uint16_t i=0; i<length; i++) {
        strip.setPixelColor(i, strip.Color(bright, 0, 0));
      }
      strip.show();
      delay(speed);
    }
      for(uint16_t bright=250; bright>5; bright-=5) {
        for(uint16_t i=0; i<length; i++) {
          strip.setPixelColor(i, strip.Color(bright, 0, 0));
        }
        strip.show();
        delay(speed);
      }
    for(uint16_t bright=5; bright<250; bright+=5) {
      for(uint16_t i=0; i<length; i++) {
        strip.setPixelColor(i, strip.Color(0, bright, 0));
      }
      strip.show();
      delay(speed);
    }
      for(uint16_t bright=250; bright>5; bright-=5) {
        for(uint16_t i=0; i<length; i++) {
          strip.setPixelColor(i, strip.Color(0, bright, 0));
        }
        strip.show();
        delay(speed);
      }
    for(uint16_t bright=1; bright<250; bright+=5) {
      for(uint16_t i=0; i<length; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, bright));
      }
      strip.show();
      delay(speed);
    }
      for(uint16_t bright=250; bright>10; bright-=5) {
        for(uint16_t i=0; i<length; i++) {
          strip.setPixelColor(i, strip.Color(0, 0, bright));
        }
        strip.show();
        delay(speed);
      }
  }
}

// Fill the dots two after two with a color, wait (ms) after each one
void colorSplit(uint16_t wait, uint32_t split1, uint32_t split2) {
  uint16_t down=half;
  uint16_t up=half+1;
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
  while(down>=0 && up<=length) {
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
    for(uint16_t i=0; i<length+300; i++) {
      strip.setPixelColor(i, rabbit);
      if(i>2) {
        strip.setPixelColor(i-3, off);
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
  for(uint16_t f=0; f<length+5; f++) {
    strip.setPixelColor(f, off);
    }
  strip.show();
  delay(wait);
}



void twinkle(uint8_t wait, uint32_t color1) {
  long randNumbers[NUM_RANDOMS];
  for (uint8_t f = 0; f < 101; f++) {
    for (int i = 0; i < NUM_RANDOMS; i++) {
      randNumbers[i] = random(i % 2 == 0 ? 0 : half + 1, i % 2 == 0 ? half : length);
    }
    for (int i = 0; i < NUM_RANDOMS / 2; i++) {
      strip.setPixelColor(randNumbers[i], color1);
    }
    strip.show();
    delay(wait);
    for (int i = NUM_RANDOMS / 2; i < NUM_RANDOMS; i++) {
      strip.setPixelColor(randNumbers[i], color1);
    }
    for (int i = 0; i < NUM_RANDOMS / 2; i++) {
      strip.setPixelColor(randNumbers[i], off);
    }
    strip.show();
    delay(wait);
    for (int i = NUM_RANDOMS / 2; i < NUM_RANDOMS; i++) {
      strip.setPixelColor(randNumbers[i], off);
    }
    strip.show();
  }
}

void setPixelRange(uint16_t start, uint16_t end, uint32_t color) {
  for (uint16_t i = start; i < end; i++) {
    strip.setPixelColor(i, color);
  }
}

void meteorChaseBlue() {
  for(uint16_t i=0; i<750; i++) {
    strip.setPixelColor(i, 0, 0, 250);
    strip.setPixelColor(i-1, 0, 0, 120);
    strip.setPixelColor(i-2, 0, 0, 100);
    strip.setPixelColor(i-3, 0, 0, 50);
    strip.setPixelColor(i-4, 0, 0, 40);
    strip.setPixelColor(i-5, 0, 0, 20);
    strip.setPixelColor(i-5, 0, 0, 0);
    if(i>50) {
      strip.setPixelColor(i-44, 0, 0, 250);
      strip.setPixelColor(i-45, 0, 0, 120);
      strip.setPixelColor(i-46, 0, 0, 100);
      strip.setPixelColor(i-47, 0, 0, 50);
      strip.setPixelColor(i-48, 0, 0, 40);
      strip.setPixelColor(i-49, 0, 0, 20);
      strip.setPixelColor(i-50, 0, 0, 0);
      }
    if(i>100) {
      strip.setPixelColor(i-94, 0, 0, 250);
      strip.setPixelColor(i-95, 0, 0, 120);
      strip.setPixelColor(i-96, 0, 0, 100);
      strip.setPixelColor(i-97, 0, 0, 50);
      strip.setPixelColor(i-98, 0, 0, 40);
      strip.setPixelColor(i-99, 0, 0, 20);
      strip.setPixelColor(i-100, 0, 0, 0);
      }
    if(i>150) {
      strip.setPixelColor(i-144, 0, 0, 250);
      strip.setPixelColor(i-145, 0, 0, 120);
      strip.setPixelColor(i-146, 0, 0, 100);
      strip.setPixelColor(i-147, 0, 0, 50);
      strip.setPixelColor(i-148, 0, 0, 40);
      strip.setPixelColor(i-149, 0, 0, 20);
      strip.setPixelColor(i-150, 0, 0, 0);
      }
    if(i>200) {
      strip.setPixelColor(i-194, 0, 0, 250);
      strip.setPixelColor(i-195, 0, 0, 120);
      strip.setPixelColor(i-196, 0, 0, 100);
      strip.setPixelColor(i-197, 0, 0, 50);
      strip.setPixelColor(i-198, 0, 0, 40);
      strip.setPixelColor(i-199, 0, 0, 20);
      strip.setPixelColor(i-200, 0, 0, 0);
      }
    if(i>250) {
      strip.setPixelColor(i-244, 0, 0, 250);
      strip.setPixelColor(i-245, 0, 0, 120);
      strip.setPixelColor(i-246, 0, 0, 100);
      strip.setPixelColor(i-247, 0, 0, 50);
      strip.setPixelColor(i-248, 0, 0, 40);
      strip.setPixelColor(i-249, 0, 0, 20);
      strip.setPixelColor(i-250, 0, 0, 0);
      }
    if(i>300) {
      strip.setPixelColor(i-294, 0, 0, 250);
      strip.setPixelColor(i-295, 0, 0, 120);
      strip.setPixelColor(i-296, 0, 0, 100);
      strip.setPixelColor(i-297, 0, 0, 50);
      strip.setPixelColor(i-298, 0, 0, 40);
      strip.setPixelColor(i-299, 0, 0, 20);
      strip.setPixelColor(i-300, 0, 0, 0);
    }
    strip.show();
    delay(2);
  }
}

void meteorChaseRed() {
  for(uint16_t i=0; i<750; i++) {
    strip.setPixelColor(i, 250, 0, 0);
    strip.setPixelColor(i-1, 120, 0, 0);
    strip.setPixelColor(i-2, 100, 0, 0);
    strip.setPixelColor(i-3, 50, 0, 0);
    strip.setPixelColor(i-4, 40, 0, 0);
    strip.setPixelColor(i-5, 20, 0, 0);
    strip.setPixelColor(i-5, 0, 0, 0);
    if(i>50) {
      strip.setPixelColor(i-44, 250, 0, 0);
      strip.setPixelColor(i-45, 120, 0, 0);
      strip.setPixelColor(i-46, 100, 0, 0);
      strip.setPixelColor(i-47, 50, 0, 0);
      strip.setPixelColor(i-48, 40, 0, 0);
      strip.setPixelColor(i-49, 20, 0, 0);
      strip.setPixelColor(i-50, 0, 0, 0);
      }
    if(i>100) {
      strip.setPixelColor(i-94, 250, 0, 0);
      strip.setPixelColor(i-95, 120, 0, 0);
      strip.setPixelColor(i-96, 100, 0, 0);
      strip.setPixelColor(i-97, 50, 0, 0);
      strip.setPixelColor(i-98, 40, 0, 0);
      strip.setPixelColor(i-99, 20, 0, 0);
      strip.setPixelColor(i-100, 0, 0, 0);
      }
    if(i>150) {
      strip.setPixelColor(i-144, 250, 0, 0);
      strip.setPixelColor(i-145, 120, 0, 0);
      strip.setPixelColor(i-146, 100, 0, 0);
      strip.setPixelColor(i-147, 50, 0, 0);
      strip.setPixelColor(i-148, 40, 0, 0);
      strip.setPixelColor(i-149, 20, 0, 0);
      strip.setPixelColor(i-150, 0, 0, 0);
      }
    if(i>200) {
      strip.setPixelColor(i-194, 250, 0, 0);
      strip.setPixelColor(i-195, 120, 0, 0);
      strip.setPixelColor(i-196, 100, 0, 0);
      strip.setPixelColor(i-197, 50, 0, 0);
      strip.setPixelColor(i-198, 40, 0, 0);
      strip.setPixelColor(i-199, 20, 0, 0);
      strip.setPixelColor(i-200, 0, 0, 0);
      }
    if(i>250) {
      strip.setPixelColor(i-244, 250, 0, 0);
      strip.setPixelColor(i-245, 120, 0, 0);
      strip.setPixelColor(i-246, 100, 0, 0);
      strip.setPixelColor(i-247, 50, 0, 0);
      strip.setPixelColor(i-248, 40, 0, 0);
      strip.setPixelColor(i-249, 20, 0, 0);
      strip.setPixelColor(i-250, 0, 0, 0);
      }
    if(i>300) {
      strip.setPixelColor(i-294, 250, 0, 0);
      strip.setPixelColor(i-295, 120, 0, 0);
      strip.setPixelColor(i-296, 100, 0, 0);
      strip.setPixelColor(i-297, 50, 0, 0);
      strip.setPixelColor(i-298, 40, 0, 0);
      strip.setPixelColor(i-299, 20, 0, 0);
      strip.setPixelColor(i-300, 0, 0, 0);
    }
    strip.show();
    delay(2);
  }
}

void meteorChaseWhite() {
  for(uint16_t i=0; i<750; i++) {
    strip.setPixelColor(i, 250, 250, 250);
    strip.setPixelColor(i-1, 120, 120, 120);
    strip.setPixelColor(i-2, 100, 100, 100);
    strip.setPixelColor(i-3, 50, 50, 50);
    strip.setPixelColor(i-4, 40, 40, 40);
    strip.setPixelColor(i-5, 20, 20, 20);
    strip.setPixelColor(i-5, 0, 0, 0);
    if(i>50) {
      strip.setPixelColor(i-44, 250, 250, 250);
      strip.setPixelColor(i-45, 120, 120, 120);
      strip.setPixelColor(i-46, 100, 100, 100);
      strip.setPixelColor(i-47, 50, 50, 50);
      strip.setPixelColor(i-48, 40, 40, 40);
      strip.setPixelColor(i-49, 20, 20, 20);
      strip.setPixelColor(i-50, 0, 0, 0);
      }
    if(i>100) {
      strip.setPixelColor(i-94, 250, 250, 250);
      strip.setPixelColor(i-95, 120, 120, 120);
      strip.setPixelColor(i-96, 100, 100, 100);
      strip.setPixelColor(i-97, 50, 50, 50);
      strip.setPixelColor(i-98, 40, 40, 40);
      strip.setPixelColor(i-99, 20, 20, 20);
      strip.setPixelColor(i-100, 0, 0, 0);
      }
    if(i>150) {
      strip.setPixelColor(i-144, 250, 250, 250);
      strip.setPixelColor(i-145, 120, 120, 120);
      strip.setPixelColor(i-146, 100, 100, 100);
      strip.setPixelColor(i-147, 50, 50, 50);
      strip.setPixelColor(i-148, 40, 40, 40);
      strip.setPixelColor(i-149, 20, 20, 20);
      strip.setPixelColor(i-150, 0, 0, 0);
      }
    if(i>200) {
      strip.setPixelColor(i-194, 250, 250, 250);
      strip.setPixelColor(i-195, 120, 120, 120);
      strip.setPixelColor(i-196, 100, 100, 100);
      strip.setPixelColor(i-197, 50, 50, 50);
      strip.setPixelColor(i-198, 40, 40, 40);
      strip.setPixelColor(i-199, 20, 20, 20);
      strip.setPixelColor(i-200, 0, 0, 0);
      }
    if(i>250) {
      strip.setPixelColor(i-244, 250, 250, 250);
      strip.setPixelColor(i-245, 120, 120, 120);
      strip.setPixelColor(i-246, 100, 100, 100);
      strip.setPixelColor(i-247, 50, 50, 50);
      strip.setPixelColor(i-248, 40, 40, 40);
      strip.setPixelColor(i-249, 20, 20, 20);
      strip.setPixelColor(i-250, 0, 0, 0);
      }
    if(i>300) {
      strip.setPixelColor(i-294, 250, 250, 250);
      strip.setPixelColor(i-295, 120, 120, 120);
      strip.setPixelColor(i-296, 100, 100, 100);
      strip.setPixelColor(i-297, 50, 50, 50);
      strip.setPixelColor(i-298, 40, 40, 40);
      strip.setPixelColor(i-299, 20, 20, 20);
      strip.setPixelColor(i-300, 0, 0, 0);
    }
    strip.show();
    delay(2);
  }
}


// back and forth slider by segment length
void KITT(uint8_t reps, uint16_t segLength, uint8_t wait, uint32_t color1) {
  for(uint8_t count=0; count<reps; count++) { 
    uint8_t chunks=length/segLength;
    for(uint8_t i=0; i<segLength; i++) {
      for(uint8_t f=0; f<chunks-1; f++) {
        uint16_t light=f*segLength+i;
        strip.setPixelColor(light, color1);
      }  
      strip.show();
      delay(wait);
      for(uint8_t f=0; f<chunks-1; f++) {
        uint16_t light=f*segLength+i;
        strip.setPixelColor(light-1, off);
      }
    }
      strip.show();
      delay(wait);
    for(uint8_t i=segLength-1; i>=1; i--) {
      for(uint8_t f=chunks-1; f>0; f--) {
        uint16_t light=f*segLength+i;
        strip.setPixelColor(light, color1);
        }  
      strip.show();
      delay(wait);
      for(uint8_t f=chunks-1; f>0; f--) {
        uint16_t light=f*segLength+i;
        strip.setPixelColor(light+1, off);
      }
    }
  }
}
