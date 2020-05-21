#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    50
#define POT         A0


CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);

}
void loop() {

  int pot_val = analogRead(POT);
  pot_val = map(pot_val, 0, 1023, 1, NUM_LEDS);
  Serial.println(pot_val);

    FastLED.clear();
    for(int led = 0; led < pot_val; led++) { 
        leds[led] = CRGB::Pink; 
    }
    FastLED.show();
  
  delay(50);
  //for (int i=0; i <= NUM_LEDS; i++){
  //    leds[i] = CRGB::Orchid;
   //   leds[i-1] = CRGB(0, 0, 0);
   //   FastLED.show();
   //   delay(300); 
   //}

}
