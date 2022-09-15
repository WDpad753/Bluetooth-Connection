#include<SoftwareSerial.h>

const int rxPin = 0;
const int txPin = 1;
SoftwareSerial mySerial(rxPin,txPin);//RX,TX.
byte packet;
int LEDPin = 13;
int Step;
char Movement;
char *StoredMovement[11];
char FinalStoredMovement;
char inData;

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
    Serial.print("Direction:");
    Serial.println(inData);
    packet ++;
    digitalWrite(LEDPin, LOW);       // Turn LED off
    if(inData == 'F')
    {
      Movement = 'F';
      StoredMovement[Step] = &Movement;
      Serial.print("Stored Movement: ");
      Serial.println(StoredMovement[Step]);
      Step++;
    }
    if(inData == 'L')
    {
      Movement = 'L';
      StoredMovement[Step] = &Movement;
      Serial.print("Stored Movement: ");
      Serial.println(StoredMovement[Step]);
      Step++;
    }
    if(inData == 'R')
    {
      Movement = 'R';
      StoredMovement[Step] = &Movement;
      Serial.print("Stored Movement: ");
      Serial.println(StoredMovement[Step]);
      Step++;
    }
    Serial.print("Stored Movement: ");
    Serial.println(StoredMovement[Step]);
    Step++;
  }
}
