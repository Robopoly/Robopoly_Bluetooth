import processing.serial.*;

// create object from Serial class
Serial btPort;

void setup()
{
  String portName = Serial.list()[0]; // change the 0 to a 1, 2, 3, etc. to match your port
  btPort = new Serial(this, portName, 9600);
  
  // set background to black, for debugging purposes
  background(0);
}

void draw()
{
}

void keyPressed()
{
  // if UP arrow key was pressed
  if (key == CODED && keyCode == UP)
  {
    // send value 0
    btPort.write(0);
    
    // set background to green
    background(222, 255, 60);
  }
}

void keyReleased()
{
  // if UP arrow key was released
  if (key == CODED && keyCode == UP)
  {
    // send value 1
    btPort.write(1);
    
    // set background to black
    background(0);
  }   
}
