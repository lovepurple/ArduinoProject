/*
	I2C 通讯的从机程序
*/

#include <Wire.h>

void setup()
{

	/* add setup code here */
	Serial.begin(9600);
	Wire.begin(4);
	Wire.onReceive(onReceiveDataFromMaster);
}

void loop()
{

	delay(500);
}

void onReceiveDataFromMaster(int numBytes)
{
	uint8_t buffer[512];
	if (Wire.available() > 0)
	{
		Wire.readBytes(buffer, numBytes);
		/*for (int i = 0; i < numBytes; ++i)
			Serial.print((char)buffer[i]);
		strstr*/
		String str = (char*)buffer;
		str = str.substring(0, numBytes);
		
		Serial.println(str);
	}
}
