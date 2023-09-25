# A place to store code for controlling Holiday lights, primarily WS2811 Strips

# This whole thing is a WIP, if you stumble across it, use at your own risk.

- Code primarily written for the Particle Photon platform. If it doesn't say otherwise it is for Photon.
- Must add neopixel.h module to each program inside the Particle Web IDE.
- For some reason have really run into issues with the WS2811 / WS2812B not working properly at times, may be a function of resistor value but not sure

# September 2023
- Replacing the pre-built 3.3v -> 5v logic level shifter with a 74AHCT125, moving everything to solder/PCB instead of bread board
- Noticed there seems to be potential EMI issues if the DIN line runs too close to the power supply (Makes sense)
 


# Notes about WS2811
 IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor acrosspixel power leads, add 300 - 500 Ohm resistor on first pixel's data input and minimize distance between Arduino and first pixel.  Avoid connecting on a live circuit...if you must, connect GND first. Put at least a 470uF Cap on the front end of the string, and more if possible.
