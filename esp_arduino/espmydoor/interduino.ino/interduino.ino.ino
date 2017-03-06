#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "It_Works";
const char* password = "hell0w0rld";

ESP8266WebServer server(80);

const int led = 2;
const String header = "<html><head><link rel='stylesheet' href='http://bit.ly/2lZIUoE'><script src='";
const String footer = "'></script></head><body><div id='a'></div></body></html>";
const String root = "http://bit.ly/2lhRKdt";

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", [](){
    digitalWrite(led, 0);
    server.send(200, "text/html", header + root + footer);
    digitalWrite(led, 1);
  });

  server.on("/openTheDoor", [](){
    digitalWrite(led, 0);
    server.send(200, "text/html", "Door opened :)");
    // TODO
    // Implement a function in the main loop to set a gpio for a given time
    // without blocking the loop
    digitalWrite(led, 1);
  });

  

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
