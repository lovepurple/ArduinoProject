//GetRemoterCode.ino
/*
	获取红外制遥控器的编码
*/

#include "IRremote.h"
#define KEY_NUM 14
#define DEBUG

int codes[KEY_NUM];
int currentIndex = 0;

const int RECEIVE_SIGN_LED_PIN = 8;
const int REMOTE_PIN = 11;

IRrecv irrecv(REMOTE_PIN);
decode_results recv_result;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0 ; i < KEY_NUM;++i)
  {
  	codes[i] = 0xFFFFFFFF;
  }

  irrecv.enableIRIn();		//enableIROut

  pinMode(RECEIVE_SIGN_LED_PIN, OUTPUT);

  Serial.begin(9600);
}

bool isValid(int decodeKey)
{
	if(decodeKey == 0xFFFFFFFF)
		return false;

	for(int i = 0;i < KEY_NUM;++i)
	{
		if(codes[i] == decodeKey)
			return false;
	}

	digitalWrite(RECEIVE_SIGN_LED_PIN,HIGH);
	delay(100);
	digitalWrite(RECEIVE_SIGN_LED_PIN,LOW);

	return true;
}



int insertCodeKey(int codeKey)
{
	if(currentIndex == 0)
	{
		codes[0] = codeKey;
		currentIndex ++;
	}
	else
	{
		currentIndex ++;
		codes[currentIndex] = codeKey;
	}

#ifdef DEBUG
	Serial.print("key: 0x");
	Serial.print(codeKey,HEX);
	Serial.print("  index:");
	Serial.println(currentIndex);
#endif
	
	return currentIndex;

}

void printCodeKeys()
{
	for(int i = 0 ; i < KEY_NUM;++i)
	{
		if(codes[i] != 0xFFFFFFFF)
		{
			Serial.print("xxxxxxxx");
			Serial.print(codes[i],HEX);
			Serial.print("  ");
		}
	}
}

int getValidKeyNum()
{
	int validKeyNum = 0;
	for(int i =0; i < KEY_NUM;++i)
	{
		if(codes[i] != 0xFFFFFFFF)
			validKeyNum++;
	}

	return validKeyNum;
}

void loop() 
{


	if(irrecv.decode(&recv_result))
	{
		int recvValue = recv_result.value;
		bool isValidKey = isValid(recvValue);

		if(isValidKey)
			insertCodeKey(recvValue);
		
		if(getValidKeyNum() < KEY_NUM)
			irrecv.resume();
		else
			printCodeKeys();
		
	}




}


