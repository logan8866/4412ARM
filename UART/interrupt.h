typedef struct GPIO{
	volatile unsigned int* GPX1CON;
	volatile unsigned int* GPX1PUD;
	volatile unsigned int* EXT_INT41CON;
	volatile unsigned int* EXT_INT41_MASK; 
	volatile unsigned int* EXT_INT41_PEND;
} GPIO_P;

//GPIO_P gpio = {0x11000c20,0x11000c28,0x11000e04,0x11000f04,0x11000f44};

typedef struct GIC{
	volatile unsigned int* ICCICR_CPU0;
	volatile unsigned int* ICDISER_CPU0;
	volatile unsigned int* ICCPMR_CPU0;
	volatile unsigned int* ICDDCR;
	volatile unsigned int* ICDIPTR14_CPU0;
	volatile unsigned int* ICCIAR_CPU0;
	volatile unsigned int* ICDICPR1_CPU0;
	volatile unsigned int* ICCEOIR_CPU0;
} GIC_P;

//GIC_P gic = {0x10480000,0x10490104,0x10480004,0x10490000,0x10490838,0x1048000c,0x10490284,0x10480010};

extern void init_irq(GPIO_P *gpio,GIC_P *gic);
extern void end_irq();
extern void handel_irq();
extern void open_led_double(); 


