/*
	Arduino ��ѹ����ģ�顣ʹ��ģ�����Ŷ���0~1024 ��Χ
	ʹ��LCD��ʾ��ѹ

	!!!!!
	A0 �� +
	GND �� -


*/

#include "LiquidCrystal.h"

uint8_t analogInputPin = A0;


//ģ�����������

float r1 = 30000.0f;
float r2 = 7500.0f;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{

	/* add setup code here */

	pinMode(A0, INPUT);
	//pinMode(13, OUTPUT);
	Serial.begin(9600);
	//lcd.begin(16, 2);
	//lcd.setCursor(0, 0);
	//lcd.clear();
	//lcd.print("hello big shabi");

}

//��ȡ��ѹ
//ע��������������ڣ�������֮���û�ˡ���C#��һ��
float getVoltage(float& voltage)
{

	//ģ�����ŵ�����
	int analogValue = analogRead(analogInputPin);

	//ģ�����ŵĵ�ѹ
	float analogVoltage = analogValue * (5.0f / 1023.0f);

	//����
	float ampere = analogVoltage / r2;


	voltage = (r1 + r2) * ampere;

	return voltage;
}


void loop()
{

	float inputValtage = 0.0f;
	getVoltage(inputValtage);

	lcd.clear();
	lcd.print(inputValtage);
	lcd.print(" V");

	delay(1000);
}

