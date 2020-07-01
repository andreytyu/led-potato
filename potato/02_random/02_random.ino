/** рандомное включение пикселей вверх и назад.
 */
#include <Adafruit_NeoPixel.h>
 
#define PIN    13          // Указываем pin
#define NUM_PIXELS  100  // Указать количество светиков в ленте
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  NUM_PIXELS,     
  PIN,        
  NEO_GRB + NEO_KHZ800    // выбрать нужную цветовую модель. GRB - Эту 
  //NEO_RGB + NEO_KHZ800    // Или RGB - эту
);
 
int brightnesses[NUM_PIXELS];
int directions[NUM_PIXELS];
int color[NUM_PIXELS];
uint8_t r = 0;
uint8_t g = 0;
uint8_t b = 0;
 
 
void setup() {
  pixels.begin();
  pixels.show();
  
  for(int i=0; i < NUM_PIXELS; i++){
    directions[i] = +1;
                brightnesses[i] = 0;
  }
}
 
void loop() {
  for(int i = 0 ; i < NUM_PIXELS ; i++)
  {
    if (/*pixels.getPixelColor(i) == 0x0 ||*/ brightnesses[i] == 0){
      // если пиксель погас
      // запускаем его снова. Чем выше значение stayBlack тем дольше он остается черным
      
 
      int stayBlack = 100;
      if (random(stayBlack) == 0)
                        { 
        directions[i] = +1; 
        brightnesses[i] = 1; 
        // выбор цвета
        if (random(2) == 0){
          // pink
          color[i] = 0;
          r = 10;
          g = 0;
          b = 3;
        }
        else if (random(2) == 1) {
          // orange
          color[i] = 1;
          r = 0;
          g = 10;
          b = 2;
        }
        else {
          // orange
          color[i] = 1;
          r = 5;
          g = 10;
          b = 10;
        }
      }
// start at zero
      r = g = b = 0;
 
    } else {
 
      // 
      brightnesses[i] = brightnesses[i] + directions[i];
      //Serial.println(i);
      ////Serial.println(brightnesses[i]);
      // change direction at some point
      int maxBrightness = 40;
      int minBrightness = 20; // минимальная яркость
      //if (brightnesses[i] == random(minBrightness,maxBrightness) || brightnesses[i] == maxBrightness)
      if (brightnesses[i] == maxBrightness)
        directions[i] = -1;
      // установка r, g, 
      if (color[i] == 0){
        // Розовый цвет
        //Serial.println("in pink");
        r = brightnesses[i];
        g = 0;
        b = brightnesses[i]/3;
      } else {
        // оранжевый цвет
        //Serial.println("in orange");
        r = brightnesses[i];
        g = brightnesses[i]/5;
        b = 0; //brightnesses[i]/5;
      }
    
    }
    
    pixels.setPixelColor(i, r, g, b);
 
  }
  // Эффект бликов. Просто уберите комментарии
  // Чем меньше значение в скобках, if (random(100) тем чаще происходят вспышки
  
  if (random(100) == 0)
  pixels.setPixelColor(random(0, NUM_PIXELS), 255, 255, 255); //Цвет вспышек задается тут
 
  pixels.show();
  delay(10);
 
}
