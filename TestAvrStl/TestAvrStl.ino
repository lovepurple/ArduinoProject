#include "ProtocolTest.h"
#include "ProtocolBase.h"
#include "MessageHandler.h"
#include<StandardCplusplus.h>
//#include<vector>
#include<map>

using namespace std;

// π”√÷∏’Î
//vector<String>* vStrList = new vector<String>;
std::map<int, String> stlMap;

void setup()
{
	/*vStrList->push_back("Hello");
	vStrList->push_back("World");*/
	Serial.begin(9600);

	//stlMap.insert(pair<int, String>(1, "Hello"));
	//stlMap.insert(pair<int, String>(2, "World"));

	//std::map<int, String>::iterator iter;
	//for (iter = stlMap.begin(); iter != stlMap.end(); iter++)
	//{
	//	Serial.print(iter->first);
	//	//Serial.println("value " + iter->second);
	//}

	Serial.print("cao");
	

	//for (int i = 0; i < vStrList->size(); ++i)
	//	Serial.print(vStrList->at(i));

	//delete vStrList;
}

void loop()
{

	/* add main program code here */

}
