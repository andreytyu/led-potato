#include <Adafruit_NeoPixel.h>                            // подключаем библиотеку
#define PIN 13                                            // Это 6 выход, куда подцеплена лента.
#define NUMPIXELS 50                                      //Число светодиодов в ленте



Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin(); //Инициализируем библиотеку Adafruit_NeoPixel
  strip.show(); //гасим светодиоды из указанного диапазона
}

void loop() {

  for(int i=NUMPIXELS; i>0; i--) {

    strip.setPixelColor(i, strip.Color(1, 0, 55));

    strip.setPixelColor(NUMPIXELS-i, strip.Color(55, 0, 0));

    strip.show();

    delay(30);
  }

}
