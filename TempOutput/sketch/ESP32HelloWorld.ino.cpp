#include <Arduino.h>
#line 1 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\ESP32HelloWorld\\ESP32HelloWorld.ino"
#line 1 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\ESP32HelloWorld\\ESP32HelloWorld.ino"
void setup();
#line 5 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\ESP32HelloWorld\\ESP32HelloWorld.ino"
void loop();
#line 1 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\ESP32HelloWorld\\ESP32HelloWorld.ino"
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("Hello World!! From ESP32");
    delay(1000);
}
