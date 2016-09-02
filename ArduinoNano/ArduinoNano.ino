void setup()
{

  /* add setup code here */
	pinMode(PIND2, OUTPUT);

}

void loop()
{
	digitalWrite(PIND2, HIGH);
	delay(1000);
	digitalWrite(PIND2, LOW);
	delay(500);

  /* add main program code here */

}
