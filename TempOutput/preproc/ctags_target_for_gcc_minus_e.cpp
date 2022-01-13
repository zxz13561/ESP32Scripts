# 1 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryWebSerever\\TryWebSerever.ino"
# 2 "d:\\Rick'sFile\\ESP32\\GitHubFiles\\ESP32Scripts\\TryWebSerever\\TryWebSerever.ino" 2

const char* ssid = "LaLaLaLaLa";
const char* password = "02134617";

WiFiServer server(80);

// Variable to store the HTTP request
String header;
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

String HTMLcode[] = {
  "HTTP/1.1 200 OK", // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  "Content-type:text/html",
  "Connection: close",
  "", // and a content-type so the client knows what's coming, then a blank line:
  "<!DOCTYPE html>",
  "<html>",
    "<title>Web Page Design</title>",
    "<head>",
      "<style type=\"text/css\">",
        "div {width:100px; height:75px; background-color:red; border:1px solid black;}",
        "#div2 {transform:rotate(30deg); -ms-transform:rotate(30deg); /* IE 9 */ -moz-transform:rotate(30deg); /* Firefox */ -webkit-transform:rotate(30deg); /* Safari and Chrome */ -o-transform:rotate(30deg); /* Opera */ background-color:yellow;}",
      "</style>",
      "<link rel=\"icon\" href=\"data:,\">",
    "</head>",
    "<body>",
      "<h1>Test Message !!!!</h1>",
      "<div><p>Hello WebServer!!</p></div>",
      "<div id=\"div2\">Hello, CSS3!</div>",
    "</body>",
  "</html>"
};

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = ""; // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) { // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c); // print it out the serial monitor
        header += c;
        if (c == '\n') { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {

            // Print all Html code from array
            for (String html : HTMLcode){
              client.println(html);
            };

            client.println(); // The HTTP response ends with another blank line
            break; // Break out of the while loop
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') { // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
