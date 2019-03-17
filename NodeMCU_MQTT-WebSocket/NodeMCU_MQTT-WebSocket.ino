#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_Password_SSID";
const char* mqtt_server = "YOUR_Server_MQTT";
const char* mqtt_user = "YOUR_User_MQTT";
const char* mqtt_pasw = "YOUR_Password_MQTT";
int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;

#define LED_1 5
#define LED_3 2
#define in_topic "/light/in"

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(LED_1, HIGH);   // Turn the LED on (Note that HIGH is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } 
  if ((char)payload[0] == '0') {
   digitalWrite(LED_1, LOW);  // Turn the LED off by making the voltage LOW
  }
if ((char)payload[0] == '2') {
   digitalWrite(LED_1, HIGH);  // Turn the LED off by making the voltage LOW
    delay(2000);
    digitalWrite(LED_1, LOW);
}
  if ((char)payload[0] == '3') {
   digitalWrite(LED_3, HIGH);  // Turn the LED off by making the voltage LOW
   delay(2000);
    digitalWrite(LED_3, LOW);
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect: clientId.c_str()
    if (client.connect("mqtt", mqtt_user, mqtt_pasw)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe(in_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(LED_1, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  pinMode(LED_3, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
