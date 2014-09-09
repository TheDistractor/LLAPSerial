// LLAPSerial.h

#ifndef _LLAPSERIAL_h
#define _LLAPSERIAL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class LLAPSerial
{
 private:
	void processMessage();
	HardwareSerial _Serial *;
 public:
	void init();
	void init(char* cI);
	void init(HardwareSerial *serIn);
	char deviceId[2];
	String sMessage;
	boolean bMsgReceived;
	char cMessage[13];  // Nice to be able to access full received message
	void SerialEvent();
    void sendMessage(String sToSend);
	void sendMessage(char* sToSend);
	void sendMessage(char* sToSend, char* valueToSend);
	void sendMessage(const __FlashStringHelper *ifsh);
	void sendMessage(const __FlashStringHelper *ifsh, char* valueToSend);
	void sendInt(String sToSend, int value);
	void sendIntWithDP(String sToSend, int value, byte decimalPlaces);
    void setDeviceId(char* cId);
	byte sleepForaWhile (word msecs);	// timed sleep using the watchdog
	void sleep(byte pinToWakeOn, byte direction = FALLING, byte bPullup = true);		// full sleep woken by pin interrupt
};

extern LLAPSerial LLAP;

#endif

