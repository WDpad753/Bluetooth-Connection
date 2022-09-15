//=====Arrays Declarations=====
//Fill Flood Maze
char Maze[11][11] = 
{ 
{'.', '-', '-', '-', '-', '-', '.'},
{'|', ' ', ' ', ' ', ' ', ' ', '|'},
{'|', ' ', ' ', ' ', ' ', ' ', '|'},
{'|', ' ', ' ', ' ', ' ', ' ', '|'},
{'|', ' ', ' ', ' ', ' ', ' ', '|'},
{'|', ' ', ' ', ' ', ' ', ' ', '|'},
{'.', '-', '-', '-', '-', '-', '.'}
};

//=====Declarations & Inital values=====
int x = 0;    //X axis used for printing the maze
int y = 0;    //Y axis used for printing the maze
int xp = 1;   //X axis used for inital position of the robot
int yp = 9;   //Y axis used for inital position of the robot
char S_value; //straigt cell value
char D_value; //down cell value
char L_value; //left cell value
char R_value; //right cell value
int i = 0;
char current_value; //current cell value
int ledPin = 53;

char PrintMaze()
{
//=====Print-out the maze=====
x = 0;
y = 0;
while(x < 11)
{
//Serial.print(Maze[y][x]);
//Serial.print(' ');
Serial1.write(Maze[y][x]);
Serial1.write(' ');
x++;
if(x > 10)
{
//Serial.print("\n");
Serial1.write("\n");
y++;
x = 0;
if(y > 10)
{
x = 11;
}
}
}
//Serial.print("\n");
//Serial.print("\n");
Serial1.write("\n");
Serial1.write("\n");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);            // Turn on Bluetooth Serial
  pinMode(ledPin, OUTPUT);         // set the Pin to output 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);       // Turn LED on
  Serial.print(PrintMaze());
  Serial1.write(PrintMaze());
//  Serial1.end();
  digitalWrite(ledPin, LOW);        // Turn LED off 
}
