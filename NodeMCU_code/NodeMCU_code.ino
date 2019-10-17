/* 
 *  Project by :
 *  Vineet Tambe 32265
 *  Siddhart Kalgoankar 32261
 *  Tanya Thakur 32266
 *  This code for the NodeMCU. It configures it as a server to re cieve data from a client and transmit 
 *  it serially to the Arduino nano. 
*/
/*
Pin Configuration = 

D0 }to Motor on the left
D1 
D2 }to Motor on the right
D3
*/


#include <ESP8266WiFi.h>
// Replace with your network credentials
const char* ssid     = "OnePlus 5";
const char* password = "12345678";

// Set web server port number to 4000
WiFiServer server(4000);


void setup() {
  Serial.begin(115200);
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
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    while (client.connected()) 
    { // loop while the client's connected
      if (client.available())
      {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);     
        //Serial.println(c);// print it out the serial monitor
      }
    }
    // Clear the header variable
  }
  Serial.println("Client disconnected.");
  Serial.println("");
}
