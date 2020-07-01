#include <Adafruit_NeoPixel.h>                            // подключаем библиотеку
#define PIN 13                                            // Это 6 выход, куда подцеплена лента.
#define NUMPIXELS 10                                      //Число светодиодов в ленте



Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin(); //Инициализируем библиотеку Adafruit_NeoPixel
  strip.show(); //гасим светодиоды из указанного диапазона
}


void loop() {
  strip.setPixelColor(0, strip.Color(100, 0, 0));
  strip.setPixelColor(2, strip.Color(0, 100, 0));
  strip.setPixelColor(5, strip.Color(0, 0, 100));
  strip.show();
}
