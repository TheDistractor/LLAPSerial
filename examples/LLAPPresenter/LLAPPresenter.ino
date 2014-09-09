/**
 A simple Powerpoint presentation remote control using Freetronics Leostick, Ciseco SRF.
 Dual button Coin Cell Board is used to sent LLAP RELAYATOG and RELAYBTOG messages.
 These are converted to keypresses for left and right arrows that can be used to advance
 and rewind Powerpoint presentations.
 
 Uses modified version of Ciseco LLAPSerial library, updated to handle alternative ports
 
 (c) Andrew D. Lindsay 2014

*/

#include "LLAPSerial.h"	// include the library
#define DEVICE_ID "PP"

void setup() {
  // Start Keyboard
  Keyboard.begin();
  // initialise serial:
  Serial1.begin(115200);

  // Initialise the LLAPSerial library
  LLAP.init(&Serial1, DEVICE_ID, false);
//  LLAP.init();
}

void loop() {
	if (LLAP.bMsgReceived) {
                if( LLAP.sMessage.equalsIgnoreCase( "RELAYBTOG") ) {
                  Keyboard.write( KEY_LEFT_ARROW ); 
                }
                if( LLAP.sMessage.equalsIgnoreCase( "RELAYATOG")  ) {
                  Keyboard.write( KEY_RIGHT_ARROW ); 
                }
		LLAP.bMsgReceived = false;	// if we do not clear the message flag then message processing will be blocked
	}
}




