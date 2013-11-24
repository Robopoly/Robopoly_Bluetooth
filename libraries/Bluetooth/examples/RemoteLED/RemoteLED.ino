/***************************************************************************************
 *
 * Title:       Remote LED
 * Description: Turn LED on and off depending on values 0 and 1 received by Bluetooth.
 * Tip:         You can send values 0 and 1 by running KeyboardToBluetooth.pde in 
 *              Processing and then pressing the UP arrow key.
 *
 ***************************************************************************************/
#include <prismino.h>
#include <Bluetooth.h>

void setup()
{
  // open Bluetooth communication and wait for port to open
  delay(1000);
  Bluetooth.begin(9600);
  delay(1000);
  
  // set pin output mode (sources current)
  pinMode(LED, OUTPUT);
}

void loop()
{
  if(Bluetooth.available())
  { 
    // read value received by Bluetooth
    char val = Bluetooth.read();
    
    if (val == 0)
    {
      // turn LED on
      digitalWrite(LED, HIGH);
    }
    else if (val == 1)
    {
      // turn LED off
      digitalWrite(LED, LOW);
    }
  }
  delay(1);
}
