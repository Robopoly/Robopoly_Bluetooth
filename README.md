# Bluetooth library for Robopoly Shield

This document explains the usage of the Bluetooth library to be used with the [Robopoly Shield](https://github.com/Robopoly/Robopoly-Shield) and the HC-05 Bluetooth module. The Bluetooth module uses the `TX1` and `RX1` lines on pins `0` and `1`, so they won't be usable for other things.

The library is written in Object-Oriented C++, it's made of a Bluetooth class named `BT` that inherits from the Arduino `Stream` class.

When the header file is included in the program (`Bluetooth.h`) the `BT` class instance is automatically created under `Bluetooth`.

## Communication methods

`int Bluetooth.available(void);`

    // ex: check if there's something in the input buffer
    if(Bluetooth.available())
    {
        // process data in buffer with Bluetooth.read()
    }
    
Same as [`Serial.available();`](http://arduino.cc/en/Serial/Available) for the Bluetooth module.

---

`int Bluetooth.peek(void);`

    // ex: get the first value in the input buffer without removing it from the buffer
    char value = Bluetooth.peek();
    
Same as [`Serial.peek();`](http://arduino.cc/en/Serial/Peek) for the Bluetooth module.

---

`int Bluetooth.read(void);`

    // ex: get the first value in the input buffer and remove it from the buffer
    char value = Bluetooth.read();
    
Same as [`Serial.read();`](http://arduino.cc/en/Serial/Read) for the Bluetooth module.

---

`void Bluetooth.flush(void);`

    // ex: wait for the transmission of outgoing serial data to complete
    Bluetooth.flush();
    
Same as [`Serial.flush();`](http://arduino.cc/en/Serial/Flush) for the Bluetooth module.

---

`void Bluetooth.write(const char *data);`

    // ex: send binary data to the Bluetooth module
    Bluetooth.write("test");
    
Same as [`Serial.write();`](http://arduino.cc/en/Serial/Write) for the Bluetooth module. If the Bluetooth connection is up this method sends data to the other module or computer.

## General configuration

`bool Bluetooth.begin(unsigned int baud = NULL);`

    // ex: to start the communication with the Bluetooth module
    Bluetooth.begin(9600);

Starts the serial communication with the Bluetooth module, by default the baud rate is 9600. If no argument is given the method will try to find it itself and it will take more time.

---

`bool Bluetooth.setName(const char *name);`

    // ex: change the broadcasted name to MyRobot
    Bluetooth.setName("MyRobot");
    
Changes the name seen when searching for Bluetooth devices on a computer or Bluetooth enabled smartphone. The name is remembered upon power cycling, so this method doesn't have to be called every time the program runs.

---

`bool Bluetooth.setPass(const char *name);`

    // ex: change the pairing password
    Bluetooth.setPass("1234");
    
When pairing the Bluetooth module with a computer or a smartphone it requires a password, by default it's `1234`. The password is remembered upon power cycling, so this method doesn't have to be called every time the program runs.

---

`bool Bluetooth.setBaud(const char *baud);`

    // ex: change the Bluetooth module baud rate
    Bluetooth.setBaud("19200");
    
In case faster data speeds are needed the baud rate (bits per second) can be changed with this method. It will take effect when the module is power cycled. **Do not select a baud rate of 115200 or higher**, it won't work for some reason and has to be reconfigured with something that can communicate that fast.

The standard available baud rates are 4800, 9600, 19200, 38400, 57600, by default it's 9600.

## Connecting to other modules

`bool Bluetooth.setMode(unsigned char mode);`

    // ex: change the pairing password
    Bluetooth.setMode(MASTER);

The HC-05 Bluetooth module can be configured as master to connect to other slave Bluetooth modules. By default the module is configured to slave mode every time the program is run, so it has to be called explicitly.

The available mode constats are `MASTER` and `SLAVE`.

---

`bool Bluetooth.search(void);`

    // ex: search for the nearby Bluetooth devices, will return a string of MAC addresses
    Bluetooth.search();

This method automatically sets the Bluetooth module mode to master and listens to the other module broadcastings and then lists their MAC addresses and signal strength.

## Miscellaneous methods

`bool Bluetooth.command(const char *cmd, const char *expReturn = "");`

    // ex: send any command to the Bluetooth module
    // if the command is successful (Bluetooth module responds with OK) the method will return true
    Bluetooth.command("AT OK", "OK");

The HC-05 module is configured with AT commands (see the [datasheet](https://www.google.ch/search?q=hc-05+bluetooth+datasheet) for all the available commands). To send an AT command this method will enable the AT mode by setting the AT pin to a logical 1 (pin 4 on the shield), send the command and terminate it with a `\r\n` as per the protocol.

The module will usually respond with `OK` for which the method will return `true` if it corresponds to the second argument `expReturn` (see the datasheet for command return values), otherwise it will always return `false`.

# Licence

This software is published under [LGPL](http://www.gnu.org/licenses/lgpl.html).