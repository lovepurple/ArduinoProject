
#include "ESP8266.h"

void setup()
{

  /* add setup code here */
	Serial.begin(9600);
	Serial.println(ESP8266_USE_SOFTWARE_SERIAL);

}

void loop()
{

  /* add main program code here */
	Serial.print("helloXXX");
	delay(1000);

}
