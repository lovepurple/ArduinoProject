int ledPin = PIND7;

void setup()
{

  /* add setup code here */
	pinMode(ledPin, OUTPUT);
	Serial.begin(38400);

}

void loop()
{

  /* add main program code here */

	if (Serial.available())
	{
		char bluetoothData = Serial.read();

		if (bluetoothData == '1')
			digitalWrite(ledPin, HIGH);
		else if (bluetoothData == '0')
			digitalWrite(ledPin, LOW);
	}
}
