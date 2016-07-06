//Kaiguan.ino
/**
	开关控制LED
	1. 

*/

int led = 13;
int switchPIN = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(switchPIN,INPUT);
}

void loop() {

	bool btnOnPress = digitalRead(switchPIN);

	if(btnOnPress)
		digitalWrite(led, HIGH);
	else
		digitalWrite(led,LOW);

}
