//Two Blinking LED
int led1=15;
int led2=16;
void setup() 
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() 
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  delay(2000);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  delay(2000);
}
