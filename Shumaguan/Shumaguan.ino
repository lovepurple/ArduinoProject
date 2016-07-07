//Shumaguan.ino

/**
	1. 单个数码管实验

*/

int currentIndex = 0;

const byte LEDs[10] = {
	00000001,
	01001111,
	00010010,
	00000110,
	01001100,
	00100100,
	00100000,
	00001111,
	00000000,
	00000100,
};

void setup() {
  // put your setup code here, to run once:
  for(int i = 2;i <= 9;++i)
  {
  	pinMode(i,OUTPUT);
  }
}

void loop() {
	for(int i = 0 ; i < 10;++i)
	{
		digitalWrite(2, LEDs[i]);
		delay(1000);
	}

}
