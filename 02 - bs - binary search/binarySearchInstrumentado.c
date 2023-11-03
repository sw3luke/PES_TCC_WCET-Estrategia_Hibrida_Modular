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
struct DATA {
  int  key;
  int  value;
}  ;
struct DATA data[15] = { {1, 100},
	     {5,200},
	     {6, 300},
	     {7, 700},
	     {8, 900},
	     {9, 250},
	     {10, 400},
	     {11, 600},
	     {12, 800},
	     {13, 1500},
	     {14, 1200},
	     {15, 110},
	     {16, 140},
	     {17, 133},
	     {18, 10} };
int binary_search(int x);
int main(void)
{
	stdout = &virtual_port;
	/* a = [0..20]*/ 
	int a = 8;
            
StartTickCounter();
	binary_search(a);
	return (0);
            
StopTickCounter();
            printf("main::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
}
int binary_search(int x)
{
  int fvalue, mid, up, low ;
  low = 0;
  up = 14;
  fvalue = -1 /* all data are positive */ ;
            
StartTickCounter();
  while (low <= up) {
            
StopTickCounter();
            printf("binary_search::bb1 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
    mid = (low + up) >> 1;
    if ( data[mid].key == x ) {  /*  found  */
            
StopTickCounter();
            printf("binary_search::bb2 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
      up = low - 1;
      fvalue = data[mid].value;
            
StopTickCounter();
            printf("binary_search::bb9 %u\r\n", GetTicks());
            ResetTickCounter();
    }
    else {  /* not found */
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
      if ( data[mid].key > x ) 	{
            
StopTickCounter();
            printf("binary_search::bb14 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
	up = mid - 1;
            
StopTickCounter();
            printf("binary_search::bb19 %u\r\n", GetTicks());
            ResetTickCounter();
      }
      else   {
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
             	low = mid + 1;
            
StopTickCounter();
            printf("binary_search::bb21 %u\r\n", GetTicks());
            ResetTickCounter();
      }
            
StopTickCounter();
            ResetTickCounter();
            printf("binary_search::bb24 0\r\n");
            StartTickCounter();    }
            
StartTickCounter();
  }
            
StopTickCounter();
            printf("binary_search::bb25 0%u\r\n", GetTicks());
            ResetTickCounter();
  return fvalue;
}