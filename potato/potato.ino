#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    172
//#define POT         A0


CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}


void runForward(int last_led, int delay_val)   {
    for(int led = 0; led < last_led; led++) {
        FastLED.clear(); 
        leds[led] = CRGB::Red;
        leds[led-1] = CRGB(0, 0, 0);
        FastLED.show();
        delay(delay_val);
    }   
};

void runBackward(int last_led, int delay_val)   {
    for(int led = 0; led < last_led; led++) {
        FastLED.clear(); 
        leds[last_led-led] = CRGB::Red;
        leds[last_led-led-1] = CRGB(0, 0, 0);
        FastLED.show();
        delay(delay_val);
    }   
};

void scatterInTheMiddle(int last_led, int delay_val) {
    CRGB color = CRGB::Red;
    for(int led = 0; led < last_led; led++) {
          FastLED.clear(); 
          leds[led] = color;
          leds[led-1] = CRGB(0, 0, 0);
          leds[last_led-led] = color;
          leds[last_led-led-1] = CRGB(0, 0, 0);
          FastLED.show();

          if (led == last_led/2) {
            color = CRGB::Green;
            };
          delay(delay_val);
      }
  
};

void loop() {

  //int pot_val = analogRead(POT);
  //pot_val = map(pot_val, 0, 1023, 1, NUM_LEDS);
  //Serial.println(pot_val);
  int delay_val = 10;
  FastLED.clear();
  //leds[5] = CRGB::Blue;
  FastLED.show();
  
  //runForward(NUM_LEDS, delay_val);
  //runBackward(NUM_LEDS, delay_val);
  
  scatterInTheMiddle(NUM_LEDS, delay_val);
  
  //FastLED.clear();
  delay(10);
  //for (int i=0; i <= NUM_LEDS; i++){
  //    leds[i] = CRGB::Orchid;
   //   leds[i-1] = CRGB(0, 0, 0);
   //   FastLED.show();
   //   delay(300); 
   //}

}
