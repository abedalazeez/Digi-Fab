const int sampleWindow = 1000;
unsigned int sample;
#define FASTLED_INTERNAL
#include <FastLED.h>
#define NUM_LEDS 24
#define DATA_PIN A1
CRGB leds[NUM_LEDS];
void setup(){
   Serial.begin(9600);
     FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
    fill_solid(leds, NUM_LEDS, CRGB(255,255,0));
    FastLED.show();}
void loop() {
   unsigned long startMillis= millis(); 
   unsigned int peakToPeak = 0;  
   unsigned int signalMax = 0;
   unsigned int signalMin = 1000;
   while (millis() - startMillis < sampleWindow){
      sample = analogRead(A0);
      if (sample < 100000){
         if (sample > signalMax){
            signalMax = sample; }
         else if (sample < signalMin){
            signalMin = sample;}}}
   peakToPeak = signalMax - signalMin;  
   Serial.println(peakToPeak);
   if (peakToPeak <1000){
         FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
    fill_solid(leds, NUM_LEDS, CRGB(0,255,0));
    FastLED.show();}
    else if (peakToPeak <2000){
         FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
    fill_solid(leds, NUM_LEDS, CRGB(255,255,0));
    FastLED.show();}
    else {
         FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
    fill_solid(leds, NUM_LEDS, CRGB(255,0,0));
    FastLED.show();}}
