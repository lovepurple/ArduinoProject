/*
	�������ʾ
	ʹ�õ���TM1637 оƬ������������ϣ�������ÿ���ֶ�ÿ�����Ŷ�Ӧһ��pin

	����ֱ��ʹ��tm1637.h
*/

#include "TM1637Display.h"

#define CLOPIN 4
#define DIOPIN 3

TM1637Display display(CLOPIN, DIOPIN);

uint8_t displayData[] = { 0b01000000,0b00100000,0b00010000,0b00001000 };

void setup()
{
	
	

}

uint8_t brightness = 0x0;

void loop()
{
	//if (brightness > 0x0f)
	//	brightness = 0;
	display.setBrightness(0x0f);

	display.setSegments(displayData);

	

	//brightness++;

	delay(2000);
}
