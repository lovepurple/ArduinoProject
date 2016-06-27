//多个LED 使用2到7 pin

int startPinIndex = 2;
int endPinIndex = 7;

int currentPinIndex;

void setup() {
  // put your setup code here, to run once:

  //打开需要的pin
  for (int i = startPinIndex ; i <= endPinIndex; ++i)
  {
    pinMode(i, OUTPUT);
  }

  currentPinIndex = startPinIndex;

}

void loop() {
  // put your main code here, to run repeatedly:

  //注意for的用法，把所有都先关了
  for (int i =  startPinIndex ; i <= endPinIndex; ++i)
  {
    digitalWrite(i, LOW);
  }

  //打开currentIndex
  digitalWrite(currentPinIndex, HIGH);
  
  delay(300);
  currentPinIndex ++;
  if (currentPinIndex > endPinIndex)
  {
    currentPinIndex = startPinIndex;

  }



}
