#include <avr/io.h>
#include <stdio.h>
#include "avr-tick-counter.h"
#define special_output_port (*((volatile char *)0x20))
int virtual_putchar(char c, FILE *unused)
{
    special_output_port = c;
    return 0;
}
 FILE virtual_port = FDEV_SETUP_STREAM(virtual_putchar, NULL, _FDEV_SETUP_WRITE);
unsigned char num_to_lcd(unsigned char a){
  switch(a){
    case 0x00:
    	StartTickCounter();
    	return 0;
    case 0x01:
    	StartTickCounter(); 
    	return 0x24;
    case 0x02:
    	StartTickCounter();
    	return 1+4+8+16+64;
    case 0x03:
    	StartTickCounter(); 
    	return 1+4+8+32+64;
    case 0x04:
    	StartTickCounter(); 
    	return 2+4+8+32;
    case 0x05:
    	StartTickCounter(); 
    	return 1+4+8+16+64;
    case 0x06:
    	StartTickCounter(); 
    	return 1+2+8+16+32+64;
    case 0x07:
    	StartTickCounter(); 
    	return 1+4+32;
    case 0x08:
    	StartTickCounter(); 
    	return 0x7F;     /* light all */
    case 0x09:
    	StartTickCounter(); 
    	return 0x0F + 32 + 64;
    case 0x0A:
    	StartTickCounter(); 
    	return 0x0F + 16 + 32;
    case 0x0B:
    	StartTickCounter(); 
    	return 2+8+16+32+64;
    case 0x0C:
    	StartTickCounter(); 
    	return 1+2+16+64;
    case 0x0D:
    	StartTickCounter(); 
    	return 4+8+16+32+64;
    case 0x0E:
    	StartTickCounter(); 
    	return 1+2+8+16+64;
    case 0x0F:
    	StartTickCounter(); 
    	return 1+2+8+16;
    }
  return 0;
}
unsigned char IN;
unsigned char OUT;
int main(void){
  stdout = &virtual_port;
  int           i;
  unsigned char a;
  int  n; /* JG */
  n = 10;
  for(i=0; i< n; i++){
      a = 0;
      if(i<5){
          OUT = num_to_lcd(a);
          StopTickCounter();
          a = 0x0;
          
          ResetTickCounter();
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb1 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x01;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb2 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x02;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x03;
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb4 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x04;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x05;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb6 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x06;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb7 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x07;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb8 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x08;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                                printf("complex::bb9 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x09;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb10 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x0A;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb11 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x0B;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb12 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x0C;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb13 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x0D;
          
                    OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb14 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x0E;
          
                              OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb15 %u\r\n", GetTicks());
            ResetTickCounter();
          a = 0x0F;
                              OUT = num_to_lcd(a);
          StopTickCounter();
                      printf("complex::bb16 %u\r\n", GetTicks());
            ResetTickCounter();
          
          
      }
    }
  return 0;
}
