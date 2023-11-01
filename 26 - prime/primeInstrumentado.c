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
typedef  unsigned char  bool;
typedef  unsigned int   uint;
bool divides (uint n, uint m);
bool even (uint n);
bool prime (uint n);
void swap (uint* a, uint* b);
bool divides (uint n, uint m) {
            
  return (m % n == 0);
}
bool even (uint n) {
            
  return (divides (2, n));
}
bool prime (uint n) {
  uint i;
            
StartTickCounter();
  if (even (n)){
            
StopTickCounter();
            printf("prime::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
      return (n == 2);
            
StopTickCounter();
            printf("prime::bb2 %u\r\n", GetTicks());
            ResetTickCounter();
  }
StopTickCounter();
ResetTickCounter(); 
StartTickCounter();
  for (i = 3; i * i <= n; i += 2) { 
            
StopTickCounter();
            printf("prime::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
      if (divides (i, n)){ /* ai: loop here min 0 max 357 end; */
            
StopTickCounter();
            printf("prime::bb9 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
        return 0; 
            
StopTickCounter();
            printf("prime::bb12 %u\r\n", GetTicks());
            ResetTickCounter();
      }
            
StopTickCounter();
            ResetTickCounter();
            printf("prime::bb13 0\r\n");
            StartTickCounter();  }
            
StartTickCounter();
  return (n > 1);
            
StopTickCounter();
            printf("prime::bb16 %u\r\n", GetTicks());
            ResetTickCounter();
            
}
void swap (uint* a, uint* b) {
            
StartTickCounter();
  uint tmp = *a;
  *a = *b; 
  *b = tmp;
            
StopTickCounter();
            printf("swap::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
}
int main () {
  stdout = &virtual_port;          
  uint x =  21649;
  uint y = 513239;
  swap (&x, &y);
            
StartTickCounter();
  return (!(prime(x) && prime(y)));
            
StopTickCounter();
            printf("main::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
            
StopTickCounter();
            ResetTickCounter();
            printf("main::bb6 Line 41 } 0\r\n");
            StartTickCounter();}