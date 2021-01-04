#include"TFT_eSPI.h"
#include "rpcWiFi.h"

TFT_eSPI tft;

 

void setup() {
    Serial.begin(115200);
  pinMode(WIO_KEY_A, INPUT_PULLUP);

  pinMode(WIO_KEY_B, INPUT_PULLUP);

  pinMode(WIO_KEY_C, INPUT_PULLUP);
    pinMode(WIO_5S_UP, INPUT_PULLUP);

    pinMode(WIO_5S_DOWN, INPUT_PULLUP);

    pinMode(WIO_5S_LEFT, INPUT_PULLUP);

    pinMode(WIO_5S_RIGHT, INPUT_PULLUP);

    pinMode(WIO_5S_PRESS, INPUT_PULLUP);
    tft.begin();

    tft.setRotation(3);

 

    tft.fillScreen(TFT_RED); // fills entire the screen with colour red
    tft.drawLine(0,0,160,120,TFT_BLACK); //drawing a black line from (0,0) to (160,120)
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

void loop() {
Serial.println("scan start");
 
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
            delay(10);
        }
    }
    Serial.println("");
 
    // Wait a bit before scanning again
    delay(5000);
}
