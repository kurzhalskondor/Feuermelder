#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "iPhoneX Kai 2018"; // SSID  of Access Point 
const char* password = "test12345"; // Password of Access Point

const char* host = "172.20.10.4";

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); //Connect to access point
  Serial.println(""); //Waiting for connection to access point
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");  
  Serial.print("Connected to ");
  Serial.println(ssid); //Printing ssid to Serial Monitor
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //Printing web-server IP to Serial Monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  HTTPClient http;

  link = "http://" + host + "/temp/";

  http.begin(link);
  int httpCode = http.GET();
  String payload = http.getString();
  
  Serial.println(httpCode);
  Serial.println(payload); 

  http.end()
}
