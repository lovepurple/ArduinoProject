//Analog.ino

/**
	1. 模拟信号引脚使用analogRead analogWrite
	2. 模拟信号读取周期100微秒	
	3. UNO的模拟信号pin A0~A5
**/

int analogPin = A5;
int analogInput = 0;

void setup() 
{
	Serial.begin(9600);
}

void loop() 
{
	analogInput = analogRead(analogPin);
	Serial.println(analogInput);

	delay(1000);
}
