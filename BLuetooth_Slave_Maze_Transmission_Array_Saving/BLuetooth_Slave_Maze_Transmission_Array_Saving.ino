#include<SoftwareSerial.h>
#include<string.h>

const int rxPin = 0;
const int txPin = 1;
SoftwareSerial mySerial(rxPin,txPin);//RX,TX.
byte packet;
int LEDPin = 13;
int Step;
char Movement;
char StoredMovement[11] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int len = strlen(StoredMovement);
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
//    Serial.print(inData);
    packet ++;
    digitalWrite(LEDPin, LOW);       // Turn LED off
    if(inData == 'F')
    {
      Movement = 'F';
      StoredMovement[Step] = Movement;
      Serial.print("Stored Movement: ");
      Serial.println(StoredMovement[Step]);
      Step++;
    }
    if(inData == 'L')
    {
      Movement = 'L';
      StoredMovement[Step] = Movement;
      Serial.print("Stored Movement: ");
      Serial.println(StoredMovement[Step]);
      Step++;
    }
    if(inData == 'R')
    {
      Movement = 'R';
      StoredMovement[Step] = Movement;
      Serial.print("Stored Movement: ");
      Serial.println(StoredMovement[Step]);
      Step++;
    }
  }
}




//void IncomingData(char *Movement)
//{
//  if(mySerial.available() != 0)
//  {
//    digitalWrite(LEDPin, HIGH);       // Turn LED on
//    char inData = mySerial.read();
//    Serial.print(inData);
//    packet ++;
//    digitalWrite(LEDPin, LOW);       // Turn LED off
//    if(inData == 'F')
//    {
//      inData = 'F';
//      *Movement = inData;
//      Serial.print("Direction:");
//      Serial.println(inData);
//      Serial.print("Movement:Forward");
//      Serial.println();
//    }
//    if(inData == 'L')
//    {
//      inData = 'L';
//      *Movement = inData;
//      Serial.print("Direction:");
//      Serial.println(inData);
//      Serial.print("Movement:Left");
//      Serial.println();
//    }
//    if(inData == 'R')
//    {
//      inData = 'R';
//      *Movement = inData;
//      Serial.print("Direction:");
//      Serial.println(inData);
//      Serial.print("Movement:Right");
//      Serial.println();
//    }
//  }
//  else if(mySerial.available() == 0);
//  {
//    for(Steps = 0;Steps < 11;Steps++)
//    {
//      StoredMovement[Steps] = Movement;
//      Serial.print("Stored Movement: ");
//      Serial.println(StoredMovement[22]);
//    }
//    int len = strlen(StoredMovement);
//    Serial.print(len);
//  }
//}

//void StoredMovementArray()
//{
//  if(mySerial.available() == 0)
//  {
//    while(Steps < 11)
//    {
//      Steps++;
//      StoredMovement[Steps] = Movement;
//      Serial.print("Stored Movement: ");
//      Serial.println(StoredMovement[22]);
//    }
//    int len = strlen(StoredMovement);
//    Serial.print(len);
//  }
//}

