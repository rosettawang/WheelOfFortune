


#include "lib/FastLED.h"
#include "lights.h"
#include "tests.h"
#include "project.h"

CRGB leds[NUM_LEDS+1];

void setup()
{
  delay( 3000 ); // power-up safety delay
  Serial.begin(9600); //enables serial output for debugging
  
  //WS2811 on pin 7, color sequence, lights data structure, and number of lights for controller
  FastLED.addLeds<LED_TYPE, LED_PIN, RGB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  FastLED.setBrightness(  BRIGHTNESS );  //sets the brightness for the strand of LEDs.  Default is 64, max is 255.

  test_leds();
 
  leds_init(); 
}

void loop()
{ 
  
//blink_light_0_example();
  //blink_lights_0_and_24();
  //blink_all_lights();
  //blink_alternating_lights();
  //fade_brightness();
  //chase();
  //chase_two_colors_with_scroll();
  //other_pattern();
  wheel();
  
  //add other functions you would like to execute here!
  
    
}
