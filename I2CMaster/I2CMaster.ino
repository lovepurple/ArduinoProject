/*
˫Arduino ʹ��I2C ͨѶ
1. Arduino Uno ,Nano ��A4 A5�����ǲ���I2C���������ţ�SDA,SCL��
2. Arduino Ҫ����
3. ʹ�� Wire.h
*/

#include <Wire.h>

void setup()
{

  /* add setup code here */
	Wire.begin();

}

byte sendByte = 0;

void loop()
{
	Wire.beginTransmission(4);
	//Wire.write(sendByte);
	//Wire.write("wocaonidaye");
	Wire.write("Hello");
	Wire.endTransmission();
	
	//sendByte++;

	delay(100);
}
