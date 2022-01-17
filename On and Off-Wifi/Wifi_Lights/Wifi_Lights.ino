#include <ThingSpeak.h>
#include <WiFi.h>
WiFiClient client;
const char *ssid = "Ravi";
const char *password = "ravikiran";
void setup() {
// put your setup code here, to run once:
  pinMode(4, OUTPUT);
  Serial.begin(115200);
  ThingSpeak.begin(client);
  delay(10);
  Serial.print("Connecting to...");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) 
  { 
    delay(500);
    Serial.println("Waiting to connect...");
  }
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
void loop() 
{
// put your main code here, to run repeatedly:
  int led = ThingSpeak.readIntField(1612969, 1);
  Serial.println(led);
  if(led == 1) 
  {
    digitalWrite(4, HIGH);
    Serial.println("LED ON");
  }
  if(led == 0) 
  {
    digitalWrite(4, LOW);
    Serial.println("LED OFF");
  }
  delay(1000);
}
