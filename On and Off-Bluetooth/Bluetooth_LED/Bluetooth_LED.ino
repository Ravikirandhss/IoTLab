#include"BluetoothSerial.h"
BluetoothSerial SerialBT;
String state;
void setup()
{
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  SerialBT.begin("BT App");
  Serial.println("The device started now you can pair with bluetooth");
}
void loop()
{
  if(Serial.available())
  {
    SerialBT.write(Serial.read());
    Serial.println("hello");
  }
  if(SerialBT.available())
  {
    state=SerialBT.read();
    Serial.print("State:");
    Serial.println(state);
    if(state.equals("49"))
    {
      digitalWrite(2,HIGH);
      Serial.println("Light On");
    }
    else if(state.equals("50"))
    {
      digitalWrite(2,LOW);
      Serial.println("Light OFF");
    }
  }
  state="";
  delay(200);
}
