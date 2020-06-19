#include "interrupt.h"

void init_irq(GPIO_P *gpio,GIC_P *gic){
	//init GPIO
	*(gpio->GPX1CON) = *(gpio->GPX1CON)&(~(0x0f<<4))|(0x0f<<4);
	*(gpio->GPX1PUD) = *(gpio->GPX1PUD)&(~(0x01<<1));
	*(gpio->EXT_INT41CON) = *(gpio->EXT_INT41CON)&(~(0x0f<<4))|(0x02<<4);
	*(gpio->EXT_INT41_MASK) = *(gpio->EXT_INT41_MASK)&(~(0x01<<1));
	//init GIC
	*(gic->ICDISER_CPU0) = (0x01<<25);
	*(gic->ICCICR_CPU0) = 0x01;
	//*(gic->ICDISER_CPU0) = (0x01<<25);
	*(gic->ICCPMR_CPU0) = 0xff;
	*(gic->ICDDCR) = 0x01;
	*(gic->ICDIPTR14_CPU0) = (0x01<<8);
}

void end_irq(){
	volatile unsigned int *EXT_INT41_PEND = 0x11000f44;
	volatile unsigned int *ICDICPR1_CPU0 = 0x10490284;
	volatile unsigned int *ICCEOIR_CPU0 = 0x10480010;
	*EXT_INT41_PEND = (0x01<<1);
	*ICDICPR1_CPU0 = 0x00;
	*ICCEOIR_CPU0 = (*ICCEOIR_CPU0) & ~(0x3ff)|57;
	/*
	//end GPIO
	*(gpio->EXT_INT41_PEND) = 0x00;
	//end GIC
	*(gic->ICDICPR1_CPU0) = 0x00;
	*(gic->ICCEOIR_CPU0) = 25;*/
}

void handel_irq(){
	open_led_double();
	end_irq();
}
