#include<ThingSpeak.h>
#include<WiFi.h>
#include "DHT.h"
#define DHTPIN 4 // what pin we're connected to
#define DHTTYPE DHT11// define type of sensor DHT 11
DHT dht (DHTPIN, DHTTYPE);
const char *ssid="Ravi";
const char *password="ravikirandhss";
const char *WriteAPI="WriteAPI";
unsigned long channelId=1222222;///Channel Id
WiFiClient client;
float h,t;
void setup() 
{
  Serial.begin(115200);
  dht.begin();
  delay(10);
  ThingSpeak.begin(client);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void upload()
{
  ThingSpeak.setField(1,t);
  ThingSpeak.setField(2,h);
  int x=ThingSpeak.writeFields(channelId,WriteAPI);
  if(x==200)
  {
    Serial.println("Successfully  Uploaded");
  }
}
void loop()
{
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("temperature:");
  Serial.println(t);
  Serial.print("Humidity:");
  Serial.println(h);
  upload();
  delay(10000);
}
