"""
	1. mega328 内置存储区域
"""
#include <EEPROM.h>

void setup() {
	pinMode(3,OUTPUT);

}

void loop() {

	digitalWrite(3,HIGH);
	EEPROM.read()
	//EEPROM一共有1K的空间，在写入的时候需要按位写入
	"""
		例如： int x = 1234;   (二进制：00000100   11010010)
							   由于1bit 只有8位
							   内存表示 ：
							   				地址		EEPROM
							   					0		0000 0100
							   					1		1101 0010
							   	所以：在存储 1234 这个值的时候，需要分开存
			EEPROM.write(0,hightByte(x));
			EEPROM.write(1,lowbyte(x));

			读取：
				byte high = EEPROM.read(0);
				byte low = EEPROM.read(1);

				int x = (high << 8) + low;			//使用左移，填0

		EEROM存储浮点数:
			union data
			{
				float f;
				int i;
			} convert;

			float f = 1.23;
			convert.f = f;

			EEPROM.write(0,highByte(convert.i));
			EEPROM.write(1,lowByte(convert.i));

			byte high = EEPROM.read(0);
			byte low = EEPROM.read(1);

			convert.i = (hight << 8) + low;
			float f = convert.f;

		EEPROM 存储字符串(按位存储字符)
		
		char* str = "Hello World";
		int i = 0;
		while(str[i] != '\0')
			EEPROM.write(i,str[i]);

		读取类似 

		清空：由于EEPROM只有1K = 1024byte 所以把区域都置为0
		for (in i = 0 ; i < 1023 ;++i)
			EEPROM.write(i,0);

		可以通过设置算法 使用位运算来存入压缩后的数据。
		例：在EEPROM里存入摄氏度：
			float tempFloat = 31.25;	

			byte tempByte = (int)tempFloat * 4;		
			EEPROM.write(0,tempByte);

			byte tempByte2 = EEPROM.read(0);
			float temp2 = (float)tempByte2 / 4.0;

	"""

	EEPROM.write();		
}

