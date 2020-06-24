#include "uart.h"

void init_uart(){
	GPA1CON = GPA1CON & (~(0x0f<<4))|(0x02<<4);
	ULCON2 = 0x03;
	UCON2 = 0x05;
	UBRDIV2 = 20;
	UFRACVAL2 = 7;
}

void print_char(char c){
	while (1){
		UTXH2 = c;
		sleep(1000000);
	}
}
