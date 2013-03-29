/*
*Nunchuck.h
*Arduino lib to interface with wii nunchuck
*/

#ifndef Nunchuck_included
#define Nunchuck_included

//identities for each field provided by the wii nunchuck
enum nunchuckItems { wii_joyX, wii_joyY, wii_accelX, wii_accelY, wii_accelZ, wii_btnC, wii_btnZ, wii_ItemCount };

//uses pins adjacent to I2C pins as power & ground for Nunchuck
void nunchuckSetPowerPins();

//initialize the I2C interface for the nunchuck
void nunchuckInit();

//Request data from the nunchuck
void nunchuckRequest();

//receive data back from nunchuck, returns true if read successful, else false
bool nunchuckRead();

//encode data to format that most wiimote drivers except
char nunchuckDecode (uint8_t x);

//return value for given item
int nunchuckGetValue(int item);




#endif 