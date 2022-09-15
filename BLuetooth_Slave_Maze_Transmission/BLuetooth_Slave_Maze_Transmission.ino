#include<SoftwareSerial.h>
const int rxPin = 0;
const int txPin = 1;
SoftwareSerial mySerial(rxPin,txPin);//RX,TX.
byte packet;
int LEDPin = 13;

void setup() 
{  
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.print("Received Maze Map:");
  Serial.print("\n");
}


void loop()
{
  if(mySerial.available() != 0)
  {
    digitalWrite(LEDPin, HIGH);       // Turn LED on
    char inData = mySerial.read();
    Serial.print(inData);
    packet ++;
    digitalWrite(LEDPin, LOW);       // Turn LED off
    if(inData == 'F')
    {
      Serial.print("Direction:");
      Serial.println(inData);
      Serial.print("Movement:Forward");
      Serial.println();
    }
    if(inData == 'L')
    {
      Serial.print("Direction:");
      Serial.println(inData);
      Serial.print("Movement:Left");
      Serial.println();
    }
    if(inData == 'R')
    {
      Serial.print("Direction:");
      Serial.println(inData);
      Serial.print("Movement:Right");
      Serial.println();
    }
  }
}
