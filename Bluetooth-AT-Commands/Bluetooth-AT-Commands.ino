void setup() 
{
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial1.available())
  {
    byte a=Serial1.read();
    Serial.write(a);
  }
  
  if(Serial.available())
  {
    byte a=Serial.read();
    Serial1.write(a);
  }
  
}
