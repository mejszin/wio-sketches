#include"TFT_eSPI.h"

TFT_eSPI tft;
const int CLR_BLUE = 0x0963B;

void setup() {
  // put your setup code here, to run once:
  tft.begin();
  tft.setRotation(3);
 
  tft.fillScreen(CLR_BLUE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
