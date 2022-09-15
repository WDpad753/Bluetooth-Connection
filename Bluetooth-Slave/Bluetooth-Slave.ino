// receiver
#include<SoftwareSerial.h>
//#define SOP '<'
//#define EOP '>'
//
//bool started = false;
//bool ended = false;
//
//byte inData[80];
//byte index;
//byte ROWS; 
//byte COLUMNS;
byte index = 0;
long  inData[byte ROWS,byte COLUMNS];
const int rxPin = 0;
const int txPin = 1;
const int LEDPin = 13;

SoftwareSerial BluetoothSerial(rxPin,txPin);//RX,TX.

void setup() 
{  
  pinMode(LEDPin, OUTPUT);
  Serial.begin(38400);
  BluetoothSerial.begin(38400);
}


void loop()
{
  if(BluetoothSerial.available() != 0)
  {
//    int ROWS = 10;
//    int COLUMNS = 10;
////    inData<byte ROWS, byte COLUMNS> = {0,0};
      inData[ROWS][COLUMNS] = BluetoothSerial.read();
//    char inData[ROWS][COLUMNS];
//    for (int i =0; i < ROWS; i++) 
//    {
//      for (int j =0; j < COLUMNS; j++)
//      {
//        inData[i][j] = BluetoothSerial.read();
//        digitalWrite(LEDPin, HIGH);       // Turn LED on
//        delay(1000);
//        digitalWrite(LEDPin, LOW);        // Turn LED off 
    //    inData[ROWS][COLUMNS] = BluetoothSerial.read();
//    ROWS++;
//    COLUMNS++;
////      inData[byte ROWS][byte COLUMNS] = BluetoothSerial.read();
    digitalWrite(LEDPin, HIGH);       // Turn LED on
//    Serial.print("Direction: ");
    Serial.println(inData[index]);
    delay(1000);
    digitalWrite(LEDPin, LOW);        // Turn LED off 
  }
}
//    inData[ROWS][COLUMNS] = BluetoothSerial.read();
//    ROWS++;
//    COLUMNS++;
////      inData[byte ROWS][byte COLUMNS] = BluetoothSerial.read();
//    digitalWrite(LEDPin, HIGH);       // Turn LED on
////    Serial.print("Direction: ");
//    Serial.println(inData[index]);
//    delay(1000);
//    digitalWrite(LEDPin, LOW);        // Turn LED off 
  }
}

//  if(BluetoothSerial.available() != 0)
//  {
//    BluetoothSerial.requestFrom(1);
//    byte ROWS = 0;
//    byte COLUMNS = 0;
////    byte  inData[] = {0,0};
//    inData[ROWS][COLUMNS] = BluetoothSerial.read();
//    ROWS++;
//    COLUMNS++;
////      inData[byte ROWS][byte COLUMNS] = BluetoothSerial.read();
//    digitalWrite(LEDPin, HIGH);       // Turn LED on
////    Serial.print("Direction: ");
//    Serial.println(inData);
//    delay(1000);
//    digitalWrite(LEDPin, LOW);        // Turn LED off 
////    switch(inData)
////    {
////      case 'F':
////      digitalWrite(LEDPin, HIGH);       // Turn LED on
////      delay(500);
////      digitalWrite(LEDPin, LOW);        // Turn LED off
////      break;
////      case 'L':
////      digitalWrite(LEDPin, HIGH);       // Turn LED on
////      delay(1000);
////      break;
////      case 'R':
////      digitalWrite(LEDPin, HIGH);       // Turn LED on
////      delay(2000);
////      digitalWrite(LEDPin, LOW);        // Turn LED off
////      break;
////    }
////  }
//// Read all serial data available, as fast as possible
////  while(Serial.available() > 0)
////  {
////    byte inChar = Serial.read();
////    if(inChar == SOP)
////    {
////       index = 0;
////       inData[index] = '\0';
////       started = true;
////       ended = false;
////       digitalWrite(LEDPin, HIGH);       // Turn LED on
////       delay(1000);
////       digitalWrite(LEDPin, LOW);        // Turn LED off 
////    }
////    else if(inChar == EOP)
////    {
////       ended = true;
////       digitalWrite(LEDPin, LOW);        // Turn LED off
////       break;
////    }
////    else
////    {
////      if(index < 79)
////      {
////        inData[index] = inChar;
////        index++;
////        digitalWrite(LEDPin, HIGH);       // Turn LED on
////        delay(1000);
////        digitalWrite(LEDPin, LOW);        // Turn LED off 
////        inData[index] = '\0';
////      }
////    }
////  }
////
////  // We are here either because all pending serial
////  // data has been read OR because an end of
////  // packet marker arrived. Which is it?
////  if(started && ended)
////  {
////    // The end of packet marker arrived. Process the packet
////
////    // Reset for the next packet
////    started = false;
////    ended = false;
////    digitalWrite(LEDPin, LOW);        // Turn LED off
////    index = 0;
////    inData[index] = '\0';
////  }
//}
//}

