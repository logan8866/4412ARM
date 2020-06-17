#include "interrupt.h"
#define GPX3CON (* (volatile unsigned int *)0x11000C60)
#define GPX3DAT (* (volatile unsigned int *)0x11000c64)
#define GPX3PUD (* (volatile unsigned int *)0x11000c6c)
#define GPK1CON (* (volatile unsigned int *)0x11000060)
#define GPK1DAT (* (volatile unsigned int *)0x11000064)
#define GPK1PUD (* (volatile unsigned int *)0x1100006c)

void init_led(){
	//GPX3PUD = GPX3PUD & (~(0x00<<1));
	GPX3CON = GPX3CON & (~(0x0f<<4)) | (0x01<<4);
	//GPK1PUD = GPK1PUD & (~(0x00<<1));
	GPK1CON = GPK1CON & (~(0x0f<<4)) | (0x01<<4);
}

void sleep(int second){
	while(second>0){
		second-=1;
	}
}

void handel_swi(int swi_num){
	GPX3DAT = GPX3DAT & (~(0x01<<1));
	GPK1DAT = GPK1DAT & (~(0x01<<1));
	GPX3DAT = GPX3DAT | (0x01<<1);
	sleep(5000000);
}

void open_led_double(){
	GPX3DAT = GPX3DAT & (~(0x01<<1)) | (0x01<<1);
	GPK1DAT = GPK1DAT & (~(0x01<<1)) | (0x01<<1);
	sleep(5000000);
	GPX3DAT = GPX3DAT & (~(0x01<<1));
        GPK1DAT = GPK1DAT & (~(0x01<<1));
}

GPIO_P gpio = {0x11000c20,0x11000c28,0x11000e04,0x11000f04,0x11000f44};
GIC_P gic = {0x10480000,0x10490104,0x10480004,0x10490000,0x10490838,0x1048000c,0x10490284,0x10480010};

int main(){
	init_led();
	init_irq(&gpio,&gic);
	int num = 0;
	while (1){
		GPX3DAT = GPX3DAT & (~(0x01<<1)) | (0x01<<1);
		sleep(1000000);
		GPX3DAT = GPX3DAT & (~(0x01<<1));
		GPK1DAT = GPK1DAT & (~(0x01<<1)) | (0x01<<1);
		sleep(1000000);
		GPK1DAT = GPK1DAT & (~(0x01<<1));
		num+=1;
		/*
		if (num>3){
			raise_swi();
			num = 0;
		}*/
	}
	return 0;
}
	

