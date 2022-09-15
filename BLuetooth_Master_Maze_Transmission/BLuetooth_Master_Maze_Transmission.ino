byte ROWS = 0;
byte COLUMNS = 0;
int ledPin = 53;

void setup() 
{
  // put your setup code here, to run once:
  Serial1.begin(38400);            // Turn on Bluetooth Serial
  pinMode(ledPin, OUTPUT);         // set the Pin to output 
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);       // Turn LED on
  Serial1.write(Maze());
  delay(1000);
  digitalWrite(ledPin, LOW);        // Turn LED off 
}

char Maze()
{
  byte ROWS = 4;
  byte COLUMNS = 5;
  boolean VerticalWalls[ROWS][COLUMNS+1];
  boolean HorizontalWalls[ROWS+1][COLUMNS];
//  boolean MazeMAP [ROWS] [COLUMNS] { //initialize to zero
//  {0, 0, 0, 0, 0},       //do not forget the ,
//  {0, 0, 0, 0, 0},
//  {0, 0, 0, 0, 0},
//  {0, 0, 0, 0, 0}
//  };
    //initialize verticalWalls (add exterior walls)
        for(byte i = 0;i < ROWS;i++)
        {
            for(byte j = 0;j<COLUMNS+1;j++)
            {
                if(j==0 || j == COLUMNS)
                {
                    VerticalWalls[i][j] = true;
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
                    HorizontalWalls[i][j]=true;
                }
            }
        }

  
//  for (byte i =0; i < ROWS; i++) {
//  for (byte j =0; j < COLUMNS; j++) {
//    Maze[i][j] = some data;
//  }
//}
//  byte ROWS = 4;
//  byte COLUMNS = 6;
//  boolean VerticalWalls[ROWS][COLUMNS+1];
//  boolean HorizontalWalls[ROWS+1][COLUMNS];
//

   for(byte i = 0;i < 2*ROWS+1;i++)
        {
            for(byte j = 0;j < 2*COLUMNS+1;j++)
            {
                //Add Horizontal Walls
                if(i%2 == 0 && j%2 == 1)
                {
                    if(HorizontalWalls[i/2][j/2] == true)
                    {
                        Serial1.print(" ---");
                    }
                    else
                    {
                        Serial1.print("    ");
                    }
                }

                //Add Vertical Walls
                if(i%2 == 1 && j%2 == 0)
                {
                    if(VerticalWalls[i/2][j/2] == true)
                    {
                        Serial1.print("|");
                    }
                    else
                    {
                        Serial1.print(" ");
                    }
                }
            }
        }
}


