//TestInclude.ino
#include "SoftwareSerial.h"
#include "ESP8266.h"

void setup() 
{
	Serial.begin(9600);
	Serial.println(ESP8266_USE_SOFTWARE_SERIAL);
}

void loop() {
}
