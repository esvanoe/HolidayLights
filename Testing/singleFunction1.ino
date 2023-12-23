/* 
This is a copy of my first fence code. THIS ONE IS FOR PLAYING/TESTING
*/ 

/* ======================= includes ================================= */
#include "Particle.h"
#include "neopixel.h"

/* ======================= functions =============================== */
void singleFunction1(uint8_t reps, uint16_t speed, uint16_t color);

/* ======================= system config ======================== */
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));


/* IMPORTANT: Set pixel COUNT, PIN and TYPE */
#define PIXEL_COUNT 350
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2811

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
  singleFunction1(3, 200, blue); // Reps, Speed, Color
}

// Strobe a color on and off and change speed
void singleFunction1(uint8_t reps, uint16_t speed, uint32_t color) {
  while(i=1; i<reps+1; i++) {
    while(l=0; l<length+1; l++) {
        strip.setPixelColor(l, color);
    }
    strip.show()
    delay(wait)
  }
}