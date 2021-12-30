# 1 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryESP32AP\\TryESP32AP.ino"
# 2 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryESP32AP\\TryESP32AP.ino" 2

const char* ssid = "ESP32APTest";
const char* passphrase = "123456789";
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
