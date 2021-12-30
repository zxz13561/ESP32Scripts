#include "WiFi.h"
 
const char* ssid = "esp32";
const char* passphrase = "1234567890";
IPAddress local_ip(192,168,100,1);
IPAddress gateway(192,168,100,1);
IPAddress subnet(255,255,255,0);
 
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