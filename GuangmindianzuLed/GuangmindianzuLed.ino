//GuangmindianzuLed.ino
/*
	使用光敏电阻在模拟pin读出结果，控制LED的亮度

	亮越亮，电阻越大
*/

int ledPin = 13;
int controllerPin = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(controllerPin, INPUT);
  Serial.begin(9600);
}

void loop() {
	int val = analogRead(controllerPin);
	Serial.println(val);
	if(val > 512)
		digitalWrite(ledPin, LOW);
	else
		digitalWrite(ledPin, HIGH);

}
