The reciever.ino file contains the code stored in the Arduino Nano of the car(which is the reciever)
The transmitter.ino file contains the code stored in the Arduino Uno of the transmitter

The transmitter code can send 4 message types to the receiver
The message types are --> 1, 2, 3, 4
Each of these correspond to a certain movement of the joystick
When the receiver in the car receives this message, the 4 motors in the car move
How the car moves when receiving these values:
1--->Forward
2--->Backward
3--->Left 
4--->Right
