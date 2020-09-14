#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define uchar unsigned char

#define LedPinRed    0
#define LedPinGreen  1
#define LedPinBlue   2

void ledInit(void)
{
	softPwmCreate(LedPinRed,  0, 100);
	softPwmCreate(LedPinGreen,0, 100);
	softPwmCreate(LedPinBlue, 0, 100);
}

void ledColorSet(uchar r_val, uchar g_val, uchar b_val)
{
	// We need to invert the value because all the LEDs are tied to +3V
	// 1-0=1 (LED on), 1-1=0 (LED off)
	softPwmWrite(LedPinRed,   (0xff-r_val));
	softPwmWrite(LedPinGreen, (0xff-g_val));
	softPwmWrite(LedPinBlue,  (0xff-b_val));
}

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed, print message to screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	//printf("linker LedPin : GPIO %d(wiringPi pin)\n",LedPin); //when initialize wiring successfully,print message to screen

	ledInit();

	while(1){
		ledColorSet(0xff,0xff,0xff);   //white	
		delay(500);
		
		ledColorSet(0xff,0x00,0x00);   //red	
		delay(500);
		ledColorSet(0x00,0xff,0x00);   //green
		delay(500);
		ledColorSet(0x00,0x00,0xff);   //blue
		delay(500);

		ledColorSet(0xff,0xff,0x00);   //yellow
		delay(500);
		ledColorSet(0xff,0x00,0xff);   //magenta
		delay(500);
		ledColorSet(0x00,0xff,0xff);   //cyan
		delay(500);
		ledColorSet(0xff,0xff,0xff);   //white
		delay(500);

		ledColorSet(0xc0,0xff,0x3e);
		delay(500);

		ledColorSet(0x94,0x00,0xd3);
		delay(500);
		ledColorSet(0x76,0xee,0x00);
		delay(500);
		ledColorSet(0x00,0xc5,0xcd);	
		delay(500);

	}

	return 0;
}
