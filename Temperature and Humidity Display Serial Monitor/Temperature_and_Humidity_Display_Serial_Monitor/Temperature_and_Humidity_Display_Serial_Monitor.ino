#include "DHT.h"
#define DHTPIN 4 // what pin we're connected to
#define DHTTYPE DHT11// define type of sensor DHT 11
DHT dht (DHTPIN, DHTTYPE);
float h,t;
void setup() 
{
  Serial.begin(115200);
  dht.begin();
}
void loop()
{
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("temperature:");
  Serial.println(t);
  Serial.print("Humidity:");
  Serial.println(h);
  delay(10000);
}
