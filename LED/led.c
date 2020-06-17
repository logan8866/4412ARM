#define GPX3CON * (volatile unsigned int *)0x11000C60
#define GPX3DAT * (volatile unsigned int *)0x11000c64
#define GPX3PUD * (volatile unsigned int *)0x11000c6c
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

int main(){
	init_led();
	while (1){
		GPX3DAT = GPX3DAT & (~(0x01<<1)) | (0x01<<1);
		sleep(1000000);
		GPX3DAT = GPX3DAT & (~(0x01<<1));
		GPK1DAT = GPK1DAT & (~(0x01<<1)) | (0x01<<1);
		sleep(1000000);
		GPK1DAT = GPK1DAT & (~(0x01<<1));
	}
}
	

