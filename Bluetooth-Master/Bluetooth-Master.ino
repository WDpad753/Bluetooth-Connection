// transmitter
// there's no button, it just sends every 2 secs


void setup()
{
  Serial1.begin(9600);
}

void loop()
{
  Serial1.write("R");
  delay (2000);
}
