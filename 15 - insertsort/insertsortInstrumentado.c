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
int a[11];
void insertsort(){
  int  i,j, temp;
            
  i = 2;
            
StartTickCounter();
  while(i <= 10){
            StopTickCounter();
            printf("insertsort::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
      j = i; 
            
StartTickCounter();
      while (a[j] < a[j-1]){
      StopTickCounter();
            printf("insertsort::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
	
	StartTickCounter();
	
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	j--;
	
        StopTickCounter();
        printf("insertsort::bb12 %u\r\n", GetTicks());
        ResetTickCounter();
StartTickCounter();
      }
            
	StopTickCounter();
	ResetTickCounter();
	StartTickCounter();
      i++;
            
            StopTickCounter();
            printf("insertsort::bb26 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
            }
}
int main(){
  stdout = &virtual_port;
  a[0] = 0;   /* assume all data is positive */
  a[1] = 11; 
  a[2]=10;
  a[3]=9; 
  a[4]=8; 
  a[5]=7; 
  a[6]=6; 
  a[7]=5;
  a[8] =4; 
  a[9]=3; 
  a[10]=2;
  
  insertsort();
  
  return 1;
}
