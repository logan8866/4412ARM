#include<stdio.h>

typedef struct GPIO{
	int *x; 
} GPIO_P;

int main(){
	int y;
	y = 400;
	struct GPIO gpio = {&y};
	printf("%d",*(gpio.x));
	return 0;
}
