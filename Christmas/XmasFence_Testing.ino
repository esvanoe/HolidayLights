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
void meteorChase(uint32_t color);

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

  meteorChase(blue);
  meteorChase(blue);
  meteorChase(blue);
  meteorChase(red);
  meteorChase(red);
  meteorChase(red);
  meteorChase(white);
  meteorChase(white);
  meteorChase(white);
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
  meteorChase(blue);
  meteorChase(blue);
  meteorChase(blue);
  meteorChase(red);
  meteorChase(red);
  meteorChase(red);
  meteorChase(white);
  meteorChase(white);
  meteorChase(white);
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
  meteorChase(blue);
  meteorChase(blue);
  meteorChase(blue);
  meteorChase(red);
  meteorChase(red);
  meteorChase(red);
  meteorChase(white);
  meteorChase(white);
  meteorChase(white);
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

void meteorChase(uint32_t color) {
  // Extract RGB components from the color parameter
  uint8_t r = (uint8_t)(color >> 16);
  uint8_t g = (uint8_t)(color >> 8);
  uint8_t b = (uint8_t)color;
  
  for(uint16_t i=0; i<750; i++) {
    // Leading light at full brightness
    strip.setPixelColor(i, r, g, b);
    // Trailing lights with decreasing brightness
    strip.setPixelColor(i-1, r*0.48, g*0.48, b*0.48);  // ~48% brightness
    strip.setPixelColor(i-2, r*0.40, g*0.40, b*0.40);  // ~40% brightness
    strip.setPixelColor(i-3, r*0.20, g*0.20, b*0.20);  // ~20% brightness
    strip.setPixelColor(i-4, r*0.16, g*0.16, b*0.16);  // ~16% brightness
    strip.setPixelColor(i-5, r*0.08, g*0.08, b*0.08);  // ~8% brightness
    strip.setPixelColor(i-6, 0, 0, 0);                // Off
    
    // Repeating pattern at intervals of 50
    for(int offset = 50; offset <= 300; offset += 50) {
      if(i > offset) {
        strip.setPixelColor(i-offset+6, r, g, b);
        strip.setPixelColor(i-offset+5, r*0.48, g*0.48, b*0.48);
        strip.setPixelColor(i-offset+4, r*0.40, g*0.40, b*0.40);
        strip.setPixelColor(i-offset+3, r*0.20, g*0.20, b*0.20);
        strip.setPixelColor(i-offset+2, r*0.16, g*0.16, b*0.16);
        strip.setPixelColor(i-offset+1, r*0.08, g*0.08, b*0.08);
        strip.setPixelColor(i-offset, 0, 0, 0);
      }
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
