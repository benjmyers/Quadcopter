/*
 * Nunchuck.cpp
 * Arduino lib to interface with wii nunchuck
*/

#include "Arduino.h" //arduino defines

#include "Wire.h" 
#include "Nunchuck.h"

//def for standard ard board
const int vccPin = 17;
const int gndPin = 16;

const int dataLength = 6;
static byte rawData[dataLength];

void nunchuckSetPowerPins()
{
	pinMode(gndPin, OUTPUT);
	pinMode(vccPin, OUTPUT);
	digitalWrite(gndPin, LOW);
	digitalWrite(vccPin, HIGH);
	delay(100);
}

void nunchuckInit()
{
	Wire.begin();
	Wire.beginTransmission(0x52);
	Wire.write((byte)0x40);
	Wire.write((byte)0x00);
	Wire.endTransmission();
}

//request data from the nunchuck
void nunchuckRequest()
{
	Wire.beginTransmission(0x52);
	Wire.write((byte)0x00);
	Wire.endTransmission();
}

//rec data back from nunchuck

bool nunchuckRead()
{
	byte cnt=0;
	Wire.requestFrom (0x52, dataLength);
	while (Wire.available()){
		byte x = Wire.read();
		rawData[cnt] = nunchuckDecode(x);
		cnt++;
	}
	nunchuckRequest();
	if (cnt >= dataLength)
		return true;
	else
		return false;
}

//encode data to format that most wiimote drivers except
char nunchuckDecode(byte x)
{
	return (x ^ 0x17) + 0x17;
}

//return the value for the given item
int nunchuckGetValue(int item)
{
	if ( item <=wii_accelZ)
		return (int)rawData[item];
	else if(item == wii_btnZ)
		return bitRead(rawData[5], 0) ? 0: 1;
	else if(item == wii_btnC)
		return bitRead(rawData[5], 1) ? 0: 1;
}
