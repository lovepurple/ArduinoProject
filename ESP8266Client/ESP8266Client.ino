/*
	ESP 8266 使用Arduino 调试
*/

#include<SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

void setup()
{
  Serial.begin(9600);

  mySerial.begin(115200);
  mySerial.println("hello,world");
}

void loop()
{ if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
