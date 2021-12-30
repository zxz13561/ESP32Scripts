#include <Arduino.h>
#line 1 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryESP32AP\\TryESP32AP.ino"
#include "WiFi.h"
 
const char* ssid = "ESP32APTest";
const char* passphrase = "123456789";
IPAddress local_ip(192,168,100,1);
IPAddress gateway(192,168,100,1);
IPAddress subnet(255,255,255,0);
 
#line 9 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryESP32AP\\TryESP32AP.ino"
void setup();
#line 14 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryESP32AP\\TryESP32AP.ino"
void loop();
#line 18 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryESP32AP\\TryESP32AP.ino"
void setupAP(void);
#line 9 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryESP32AP\\TryESP32AP.ino"
void setup() {
  Serial.begin(115200);
  setupAP();
}
 
void loop() {
   
}
 
void setupAP(void) {
  WiFi.softAP(ssid, passphrase, 6);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.println("run softap");
}
