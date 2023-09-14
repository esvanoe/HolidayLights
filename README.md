# HolidayLights

# A place to store code for controlling Holiday lights, primarily WS2811 Strips

- Code primarily written for the Particle Photon platform. If it doesn't say otherwise it is for Photon.
- Must add neopixel.h module to each program inside the Particle Wed IDE.
- For some reason have really run into issues with the WS2811 / WS2812B not working properly at times, may be a function of resistor value but not sure



# Notes about WS2811

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
//
// Put at least a 470uF Cap on the front end of the string, and more if possible.
