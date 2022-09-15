// receiver
#include<SoftwareSerial.h>
#include <CmdMessenger.h>
#include "Maze_Map.h"

const int rxPin = 0;
const int txPin = 1;
const int LEDPin = 13;
int flag = 0;         // a flag to prevent duplicate messages

SoftwareSerial BluetoothSerial(rxPin,txPin);//RX,TX.
Maze<4,6> maze;                    // Defining the rows and columns of the maze

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  Serial.begin(38400);
  BluetoothSerial.begin(38400);
  maze.mouseRow = 4;
  maze.mouseColumn = 1;
  maze.mouseHeading = NORTH;
  Serial.println("                      Received Maze                          ");
//  maze.solve();
  maze.print();
  digitalWrite(LEDPin, LOW);       // Turn LED off
}
void loop() 
{
  // put your main code here, to run repeatedly:
  inData();
}

void inData()
{
  if (BluetoothSerial.available() != 0)
  {
    Serial.print('#');
    char inData = BluetoothSerial.read();
    Serial.print("Direction: ");
    Serial.println(inData);
    if (inData == 'F')
    {
      digitalWrite(LEDPin, HIGH);       // Turn LED on
      maze.mouseHeading = NORTH;
      maze.mouseRow -= 1;
      // Adding Walls //
      maze.addWalls(WEST);
      maze.addWalls(EAST);
      maze.solve();
      maze.print();
      delay(500);
      digitalWrite(LEDPin, LOW);        // Turn LED off
    }
    else if (inData == 'L')
    {
      digitalWrite(LEDPin, HIGH);       // Turn LED on
      maze.mouseHeading = WEST;
      maze.mouseColumn -= 1;
      // Adding Walls //
      maze.addWalls(NORTH);
      maze.addWalls(EAST);
      maze.solve();
      maze.print();
      delay(1000);
    }
    else if (inData == 'R')
    {
      digitalWrite(LEDPin, HIGH);       // Turn LED on
      maze.mouseHeading = EAST;
      maze.mouseColumn += 1;
      // Adding Walls //
      maze.addWalls(NORTH);
      maze.addWalls(WEST);
      maze.solve();
      maze.print();
      delay(2000);
      digitalWrite(LEDPin, LOW);        // Turn LED off
    }
  }
  else
  {
    flag=0;
  }
}

