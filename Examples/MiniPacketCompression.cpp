/* change "/*" to "//*" to activate


#include <Arduino.h>
#include "BitChopper.h"
#include "MiniPacket.h"
void setup()
{
  // put your setup code here, to run once:
  while (!Serial)
    delay(100);
}

void loop()
{

  BitChopper bitChopper;      //use default constructor
  uint32_t data = 3723476863; //110 1110 11110 111110 1111110 1111111 Example uncompressed binary data

  config testConfig;
  testConfig.resolution = 6;
  testConfig.offset = 14; // how many bits over from the zero index relavent bits are

  Serial.println(data, BIN);
  int compressedData = bitChopper.compress(testConfig, data); //111110 after compression

  int idLength = 5;
  int exampleID = 21;
  int dataLength = testConfig.resolution;
  MiniPacket example(idLength, dataLength);
  example.setID(exampleID);
  example.setData(compressedData);
  //MiniPacket is ready to be sent over CAN Bus

  //On Other Size
  int extractedData = bitChopper.extract(testConfig, example.getData());

  //print out extracted data with clean formatting
  for (int i = 0; i < 32 - testConfig.resolution - testConfig.offset; i++)
  {
    Serial.print('0');
  }
  Serial.println(extractedData, BIN);

  while (true)
    delay(3000);
}
//*/
