all:
	arm-none-linux-gnueabi-gcc -fno-builtin-nostdinc -c -nostdlib -o  start.o start.s
	arm-none-linux-gnueabi-gcc -fno-builtin-nostdinc -c -nostdlib -o led.o led.c
	arm-none-linux-gnueabi-ld start.o led.o -Tmap.lds -o led.elf
	arm-none-linux-gnueabi-objcopy -O binary led.elf led.bin
	arm-none-linux-gnueabi-objdump -D led.elf > led.dis

clean:
	rm -rf *.bak start.o led.o *.elf *.bin *.dis
