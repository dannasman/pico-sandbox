#include <rp2350/resets.h>

void main() {
	//Release IO_BANK and PADS resets
	*(unsigned volatile *)0x40020000 &= 0xFFFFFDBF;
	while((*(unsigned volatile *)0x40020008 & 0x00000240) != 0x00000240)
		continue;
	//Configure PAD25 and PIN25
	*(unsigned volatile *)0x40038068 = 0;
	*(unsigned volatile *)0x400280CC = 5;
	//Enable GPIO25 and Set to 1
	*(unsigned volatile *)0xd0000038 = 0x02000000;
	//Run forever
	while(1) {
		//Toggle LED
		*(unsigned volatile *)0xd0000028 = 0x02000000;
		//Delay
		for( volatile unsigned int i=0; i<120000; i++ )
			continue;
	}
}
