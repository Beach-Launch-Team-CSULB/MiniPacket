
//platformIO only allows one setup() and loop() to be declared, 
//hence these example sketches are commented out. 
/* change "/*" on left to "//*" to activate sketch


#include <Arduino.h>
#include "MiniPacket.h"
void setup()
{
  while(!Serial);
}

void loop()
{
  int idLength = 5;
  int dataLength = 7;
  MiniPacket example(idLength,dataLength);
  example.setID((1<<idLength)-1);//max representable ID
  example.setData((1<<dataLength)-1);//max representable ID

  Serial.print("ID: ");
  Serial.println(example.getID(),BIN);

  Serial.print("DATA: ");
  Serial.println(example.getData(),BIN);
  //ready to be sent over CAN Bus

  while(1)
    delay(1000);
}
//*/