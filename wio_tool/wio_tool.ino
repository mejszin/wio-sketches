#include"TFT_eSPI.h"

const int CLR_BLUE      = 0x963B;
const int CLR_LIGHTGREY = 0xE73C;
const int CLR_DARKGREY  = 0x7BEF;

const int SCREEN_WIDTH  = 320;
const int SCREEN_HEIGHT = 240;
const int STATUS_HEIGHT = 32;
const int MENU_ITEM_HEIGHT = 24;

String menu_items[] = {
  "Wi-Fi",
  "Sound Volume",
  "Backlight Brightness",
  "Storage",
  "Update",
  "About"
};

int menu_item_count = 6;

TFT_eSPI tft;

int selected_menu_index = 0;

void setup() {
  Serial.begin(115200);
  // Set pins
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  // Set screen
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_WHITE);
  draw_menu();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(WIO_5S_UP) == LOW) {
    if (selected_menu_index > 0) {
      selected_menu_index -= 1;
      draw_menu();
    }
  }
  else if (digitalRead(WIO_5S_DOWN) == LOW) {
    if (selected_menu_index < menu_item_count - 1) {
      selected_menu_index += 1;
      draw_menu();
    }
  }
  Serial.println(menu_items[selected_menu_index]);
  Serial.println(selected_menu_index);
  Serial.println(menu_item_count);
  Serial.println("");
  delay(200);
}

void draw_menu() {
  //tft.fillScreen(TFT_WHITE);
  tft.fillRect(0, 0, SCREEN_WIDTH, STATUS_HEIGHT, CLR_LIGHTGREY);
  // Draw background
  for (int i = 0; i < menu_item_count; i++) {
    int color = (i == selected_menu_index) ? CLR_BLUE : TFT_WHITE;
    tft.fillRect(0, STATUS_HEIGHT + 1 + (i * MENU_ITEM_HEIGHT), SCREEN_WIDTH, MENU_ITEM_HEIGHT  - 1, color);
  }
  // Draw lines
  for (int i = 0; i < menu_item_count + 1; i++) {
    tft.drawFastHLine(0, STATUS_HEIGHT + (i * MENU_ITEM_HEIGHT), SCREEN_WIDTH, CLR_DARKGREY);
  }
  // Draw text
  for (int i = 0; i < menu_item_count; i++) {
    tft.setTextColor(TFT_BLACK, (i == selected_menu_index) ? CLR_BLUE : TFT_WHITE);
    tft.drawString(menu_items[i], 8, 9 + STATUS_HEIGHT + (i * MENU_ITEM_HEIGHT));
  }
}
