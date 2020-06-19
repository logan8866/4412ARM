#include "uart.h"

void init_uart(){
	GPA1CON = GPA1CON & (~(0x0f<<4))|(0x04);
	ULCON2 = 0x03;
	UCON2 = 0x05;
	UBRDIV2 = 107;
	UFRACVAL2 = 8;
}

void print_char(char *c){
	while (!UTRSTAT2&(0x02)){
		UTXH2 = *c;
	}
}
