#include <Arduino.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

template <byte ROWS,byte COLUMNS>
class Maze
{
private:
    // vertical walls array
    boolean verticalWalls[ROWS][COLUMNS+1];

    // horizontal walls array
    boolean horizontalWalls[ROWS+1][COLUMNS];

public:
    // value array
    byte values[ROWS][COLUMNS];
    
    byte mouseRow;
    byte mouseColumn;
    byte mouseHeading;

    //Constructor method (called when the maze is created)
    Maze()
    {
        //initialize verticalWalls (add exterior walls)
        for(byte i = 0;i < ROWS;i++)
        {
            for(byte j = 0;j<COLUMNS+1;j++)
            {
                if(j==0 || j == COLUMNS)
                {
                    verticalWalls[i][j] = true;
                }
            }
        }

        //initialize horizontalWalls (add exterior walls)
        for(byte i = 0;i < ROWS + 1;i++)
        {
            for(byte j=0;j<COLUMNS;j++)
            {
                if(i==0 || i==ROWS)
                {
                    horizontalWalls[i][j]=true;
                }
            }
        }
    }
    
    //Add your code here
    void solve()
    {
      for (byte i = 0; i < ROWS; i++)
      {
        for (byte j = 0; j < COLUMNS; j++)
        {
          values[i][j] = 255;
        }
      }
    }

    void addWalls(byte CardinalDirection)
    {
      switch(CardinalDirection)
      {
        case NORTH:
        horizontalWalls[mouseRow][mouseColumn] = true;
        break;
        case EAST:
        verticalWalls[mouseRow][mouseColumn + 1] = true;
        break;
        case SOUTH:
        horizontalWalls[mouseRow + 1][mouseColumn] = true;
        break;
        case WEST:
        verticalWalls[mouseRow][mouseColumn] = true;
        break;
      }
    }

    void removeaddWalls(byte CardinalDirection)
    {
      switch(CardinalDirection)
      {
        case NORTH:
        horizontalWalls[mouseRow][mouseColumn] = false;
        break;
        case EAST:
        verticalWalls[mouseRow][mouseColumn + 1] = false;
        break;
        case SOUTH:
        horizontalWalls[mouseRow + 1][mouseColumn] = false;
        break;
        case WEST:
        verticalWalls[mouseRow][mouseColumn] = false;
        break;
      }
    }
    
    /*Do not change or add code below this line
    
    NanoMouseMaze Print Function Version 2
    This version of the print function has been modified to print
    any size maze (the previous version could not print large
    mazes) and to work with the btMonitor Android App I wrote,
    which is available through my free online course at:
    http://udemy.com/nanomouse
    Scroll down to "Wireless Debugging with the Bluetooth Module"
    and go to the Downloadable Materials section of the lecture.*/
    
    byte print()
    {
        for(byte i = 0;i < 2*ROWS+1;i++)
        {
            for(byte j = 0;j < 2*COLUMNS+1;j++)
            {
                //Add Horizontal Walls
                if(i%2 == 0 && j%2 == 1)
                {
                    if(horizontalWalls[i/2][j/2] == true)
                    {
                        Serial.print(" ---");
                    }
                    else
                    {
                        Serial.print("    ");
                    }
                }

                //Add Vertical Walls
                if(i%2 == 1 && j%2 == 0)
                {
                    if(verticalWalls[i/2][j/2] == true)
                    {
                        Serial.print("|");
                    }
                    else
                    {
                        Serial.print(" ");
                    }
                }

                //Add Flood Fill Values
                if(i%2 == 1 && j%2== 1)
                {
                    if((i-1)/2 == mouseRow && (j-1)/2 == mouseColumn)
                    {
                        if(mouseHeading == NORTH)
                        {
                            Serial.print(" ^ ");
                        }
                        else if(mouseHeading == EAST)
                        {
                            Serial.print(" > ");
                        }
                        else if(mouseHeading == SOUTH)
                        {
                            Serial.print(" v ");
                        }
                        else if(mouseHeading == WEST)
                        {
                            Serial.print(" < ");
                        }
                    }
                    else
                    {
                        byte value = values[(i-1)/2][(j-1)/2];
                        if(value >= 100)
                        {
                            Serial.print(value);
                        }
                        else
                        {
                            Serial.print(" ");
                            Serial.print(value);
                        }
                        if(value < 10)
                        {
                            Serial.print(" ");
                        }
                    }
                }
            }
            Serial.print("\n");
        }
        Serial.print("\n");
    }
};
