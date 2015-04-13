#include <stdio.h>

#define PINSEL4 0x4002C010
#define FIO2DIR 0x2009C040
#define FIO2SET 0x2009C058
#define FIO2CLR 0x2009C01C

int main(void)

{
 unsigned int volatile * setGPIO = (unsigned int *)PINSEL4;
 unsigned int volatile * setDIR = (unsigned int *)FIO2DIR;
 unsigned int volatile * setHIGH = (unsigned int *)FIO2SET;
 unsigned int volatile * setLOW = (unsigned int *)FIO2CLR;

 *setGPIO = *setGPIO & 0xFFFFFFCF;
 *setDIR = (*setDIR & 0x0 ) | 0x00000004;
 *setHIGH = (*setHIGH & 0x0 ) | 0x00000004;
 *setLOW = (*setLOW & 0x0 ) | 0x00008000;

 return 0;

}



