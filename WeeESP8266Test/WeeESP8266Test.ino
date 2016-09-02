//WeeESP8266Test.ino

#include "ESP8266.h"
#include "SoftwareSerial.h"

#define SSID "TianShangRenJian"
#define PASSWORD "abc123456"
#define HOSTIP "192.168.1.100"
#define HOSTPORT 8234
#define TICK_RATE 1.0 / 30

SoftwareSerial communicationSerial(11, 10);

ESP8266 esp8266WifiModuel(communicationSerial, 9600);


void crateTcpConnection(const String, const uint32_t);
void sendConnectedData(const String);

CONNECTION_STATUS current_connection_status;

void setup()
{
	Serial.begin(9600);

	//JOIN AP
	if (esp8266WifiModuel.joinAP(SSID, PASSWORD))
	{
		Serial.print("JOIN Succeed! Local IP:");
		Serial.print(esp8266WifiModuel.getLocalIP());

		delay(1000);
	}
	else
	{
		Serial.print("JOIN SSID :");
		Serial.print(SSID);
		Serial.println("failure");
	}

	//如果是TCP或UDP连接使用enableMUX
	esp8266WifiModuel.disableMUX();

	crateTcpConnection(HOSTIP, HOSTPORT);

	sendConnectedData("Hello This is arduino client \n");

	
}

void loop()
{

	//接受的是char的buffer
	uint8_t buffer[1024] = { 0 };

	current_connection_status = esp8266WifiModuel.getConnectionStatus();
	if (current_connection_status == CONNECTION_STATUS::CONNECTED)
	{
		

	}
	else
	{
		crateTcpConnection(HOSTIP, HOSTPORT);
	}

	
	delay(TICK_RATE);
}

void crateTcpConnection(const String hostIP, const uint32_t port)
{
	if (esp8266WifiModuel.createTCP(hostIP, port))
	{
		Serial.println("create tcp ok");
		current_connection_status = CONNECTION_STATUS::CONNECTED;
	}
	else
	{
		Serial.println("create tcp error");
	}
}

void sendConnectedData(const String dataContent)
{
	if (current_connection_status == CONNECTION_STATUS::CONNECTED)
	{
		const char* sendContent = dataContent.c_str();

		esp8266WifiModuel.send((const uint8_t*)sendContent, strlen(sendContent));
	}
}

//void onRecvMessage()