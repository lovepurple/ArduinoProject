#include <Wire.h>

void setup()
{
	Wire.begin();
	Serial.begin(9600);
	Serial.println("I2C Scanner");
}

void loop()
{
	byte error;
	int deviceNum = 0;

	//8位地址，7位是有效的
	for (int address = 1; address < 127; ++address)
	{
		Wire.beginTransmission(address);
		error = Wire.endTransmission();

		if (error == 0)
		{
			Serial.print("I2C device found at address 0x");
			if (address < 16)
				Serial.print("0");

			Serial.print(address, HEX);
			Serial.println(" | ");
			deviceNum++;

		}
	}

	delay(5000);


}
