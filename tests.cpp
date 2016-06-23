//tests.cpp - learn how to control the lights here!
//by Alison N. Norman

#include "tests.h"

//blink the light closest to the controller
void blink_light_0_example()
{
  leds[0]=CRGB::Chartreuse; //defined in colors (pixeltypes.h), sets led 0 to white in strand

  FastLED.delay(500); //pauses the program for the specified number of milliseconds
                       //do this to display the current light settings for a particular amount of time
                       //calls show, which mirrors the values in leds to the strand

  leds[0]=CRGB::Black; //Black turns the led off

  FastLED.delay(500);
  

}

//Function to blink the first and last lights
void blink_lights_0_and_24()
{
    leds[0]=CRGB::Blue; //defined in colors (pixeltypes.h), sets led 0 to white in strand
    leds[24] = CRGB::Blue;

  FastLED.delay(1000); //pauses the program for the specified number of milliseconds
                       //do this to display the current light settings for a particular amount of time
                       //calls show, which mirrors the values in leds to the strand

  leds[24]=CRGB::Black; //Black turns the led off
  leds[0] = CRGB::Black;

  FastLED.delay(100);

}

//Function to blink all lights
void blink_all_lights()
{
  for (int i=0; i<=24; i++){
  
  leds[i]=CRGB::Chartreuse; //defined in colors (pixeltypes.h), sets led 0 to white in strand
  
  }
  FastLED.delay(500);
  for (int i=0; i<=24; i++){
    leds[i]=CRGB::Black;
    }
  FastLED.delay(500);
  
}

//Function to blink every other light
void blink_alternating_lights()
{
  for (int i=0; i<=24; i+=2){
  
  leds[i]=CRGB::Chartreuse; //defined in colors (pixeltypes.h), sets led 0 to white in strand
  
  }
  FastLED.delay(650);

  for (int i=0; i<=24; i+=2){
    leds[i]=CRGB::Black;
  }
  FastLED.delay(0);
    for (int i=1; i<=24; i+=2){
  
  leds[i]=CRGB::Chartreuse; //defined in colors (pixeltypes.h), sets led 0 to white in strand
  
  }
  FastLED.delay(650);
  for (int i=1; i<=24; i+=2){
    leds[i]=CRGB::Black;
    }
  FastLED.delay(0);
  
}

//Function to fade the brightness of all
void fade_brightness()
{
  //first give each a color
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i].r=random(254);   //random is in the Arduino library.  Sends back a random number between 0 and its argument, inclusive.
    leds[i].g=random(43);   //One way to set the color of the LEDs to a custom color.
    leds[i].b=random(12);
   FastLED.delay(500);
  }
  
  for(int brightness=200; brightness>=0; brightness++)
  {
    FastLED.setBrightness(brightness);
 
   FastLED.delay(500);
   }
}


void chase()
{
for (int i=0; i<=24; i++){
  
  leds[i]=CRGB::Chartreuse; //defined in colors (pixeltypes.h), sets led 0 to white in strand
  FastLED.delay(500);
    leds[i]=CRGB::Black;
    }
  FastLED.delay(0);
}

void chase_two_colors_with_scroll(){
//while rand

  
  leds[NUM_LEDS]=CRGB::Chartreuse;
    FastLED.delay(1500);
  leds_scroll();
 for (int i=0; i<=24; i++){
    leds[NUM_LEDS]=CRGB::Crimson;
    FastLED.delay(1500);
  leds_scroll();

 }

 //all black
}

void other_pattern(){  
for (int i=0; i<=24; i++){
  
  leds[i]=CRGB::Chartreuse; //defined in colors (pixeltypes.h), sets led 0 to white in strand
  FastLED.delay(100);
    leds[i]=CRGB::Black;
    }
  FastLED.delay(0);
  for (int i=0; i<=24; i++){
  
  leds[i]=CRGB::Crimson; //defined in colors (pixeltypes.h), sets led 0 to white in strand
  FastLED.delay(100);
    leds[i]=CRGB::Black;
    }
  FastLED.delay(0);
  

}







void wheel(){
    
 int slows = 4;
 for (int i=0; i<=4; i++){
    rotateOneSlice (CRGB::DarkRed, slows);
    rotateOneSlice (CRGB::Yellow, slows);
    rotateOneSlice (CRGB::Green, slows);
    rotateOneSlice (CRGB::Blue, slows);
    rotateOneSlice(CRGB::Purple, slows);
     slows = slows * 2.5;
 }
 
randomSeed(analogRead(0));
  int stops = random(0,4);
  rotateOneSliceLater (CRGB::DarkRed);

   if (stops == 0) {
      wheelStops ();
   }
   
  if(stops > 0) {
     rotateOneSliceLater (CRGB::Yellow);
     if (stops == 1) {
      wheelStops();
     }
  }
  
  if(stops > 1) {
   rotateOneSliceLater (CRGB::Green);
   if (stops == 2) {
    wheelStops();
  }
  }
  
  if(stops > 2) {
   rotateOneSliceLater (CRGB::Blue);
   if (stops == 3) {
    wheelStops();
  } 
  }
  
  if(stops > 3) {
   rotateOneSliceLater (CRGB::Purple);
   if (stops == 4) {
    wheelStops();
  }
  }
}

 void wheelStops ()
 {
  blinkslow();
          leds[25]=CRGB::Black;
        FastLED.delay(1500);

  for (int i=0; i<=24; i++){
  
  leds[i]=CRGB::Yellow; //defined in colors (pixeltypes.h), sets led 0 to white in strand
  
  }
  FastLED.delay(0);
  blinking();
    
    
    
    
 }

void blinkslow()
{
    for (int blinks=1; blinks <7; blinks ++){
    for(int brightness=1; brightness<255; brightness+=4)
    {
        FastLED.setBrightness(brightness);
        FastLED.delay(1);
    }
}
}

void blinking()
{
  for (int blinks=1; blinks <300; blinks ++){
    for(int brightness=1; brightness<255; brightness+=10)
    {
        FastLED.setBrightness(brightness);
        FastLED.delay(1);
    }
  }  
}

void rotateOneSlice (CRGB sliceColor, int slows)
{
    for (int i=0; i<=4; i++){ 
    leds[NUM_LEDS]= sliceColor;
    FastLED.delay(slows);
    leds_scroll();
   }
}

void rotateOneSliceLater (CRGB sliceColor)
{
    for (int i=0; i<=4; i++){ 
    leds[NUM_LEDS]= sliceColor;
    FastLED.delay(390);
    leds_scroll();
   }
}






