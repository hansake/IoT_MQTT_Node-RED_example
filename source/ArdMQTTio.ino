/*
 Basic MQTT I/O example
 This sketch demonstrates the basic capabilities of the library.
 It connects to an MQTT server then:
  - publishes input pin connected to switch to the topic "inArdPin"
  - subscribes to the topic "outArdPin", controlling LED
    the MQTT messages are "true" or "false"
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function.
 
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
IPAddress server(192, 168, 1, 162);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  
  if (memcmp(payload, "true", 4) == 0) {
    digitalWrite(5, HIGH);
    Serial.print(" LED on"); 
  }
  if (memcmp(payload, "false", 5) == 0) {
    digitalWrite(5, LOW);
    Serial.print(" LED off");
  }
  Serial.println();
}

EthernetClient ethClient;
PubSubClient client(ethClient);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, announce inArdPin to "false" for switch
      client.publish("inArdPin", "false", 5);
      // ... and resubscribe for outArdPin for LED
      client.subscribe("outArdPin");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(5, OUTPUT);
  pinMode(6, INPUT);

  client.setServer(server, 1883);
  client.setCallback(callback);

  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
}

void loop()
{
  int inputPin;
  static int lastInput;
  
  if (!client.connected()) {
    reconnect();
  }
  inputPin = digitalRead(6);
  if (inputPin != lastInput) {
    lastInput = inputPin;
    if (inputPin == HIGH) {
      Serial.println("input pin HIGH");
      client.publish("inArdPin", "false", 5);
    }
    if (inputPin == LOW) {
      Serial.println("input pin LOW");
      client.publish("inArdPin", "true", 4);
    }
  }
  client.loop();
}
