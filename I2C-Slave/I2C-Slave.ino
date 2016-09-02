//I2C´Ó»ú

#include "Wire.h"

void setup()
{
	Wire.begin(4);
	Wire.onReceive(receiveEvent);

  /* add setup code here */
	Serial.begin(9600);
}

void loop()
{

  /* add main program code here */
	delay(100);

}

void receiveEvent(int howMany)
{
	while (Wire.available() > 1)
	{
		char c = Wire.read();
		Serial.println(c);
	}

}
