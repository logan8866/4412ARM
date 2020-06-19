#define GPA1CON *(volatile unsigned int*)0x11400020
#define ULCON2 *(volatile unsigned int*)0x13820000
#define UCON2 *(volatile unsigned int*)0x13820004
#define UTRSTAT2 *(volatile unsigned int*)0x13820010
#define UTXH2 *(volatile unsigned int*)0x13820020
#define URXH2 *(volatile unsigned int*)0x13820024
#define UBRDIV2 *(volatile unsigned int*)0x13820028
#define UFRACVAL2 *(volatile unsigned int*)0x1382002c

extern void print_char(char *c);
extern void init_uart();
