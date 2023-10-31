/* MDH WCET BENCHMARK SUITE. File version $Id: janne_complex.c 7800 2018-01-19 12:43:12Z lkg02 $ */
/*----------------------------------------------------------------------
 *  WCET Benchmark created by Andreas Ermedahl, Uppsala university, 
 *  May 2000.  
 *
 *  The purpose of this benchmark is to have two loop where the inner 
 *  loops max number of iterations depends on the outer loops current 
 *  iterations. 
 *
 * The example appeard for the first time in: 
 * 
 *  @InProceedings{Ermedahl:Annotations,
 * author =       "A. Ermedahl and J. Gustafsson",
 * title =        "Deriving Annotations for Tight Calculation of Execution Time",
 * year =         1997,
 * month =        aug,
 * booktitle =    EUROPAR97,
 * publisher =    "Springer Verlag",
 * pages =        "1298-1307"
 * }
 *
 * The result should be the following:
 *   outer loop:       1   2   3   4   5   6   7   8   9   10   11 
 *   inner loop max:   5   9   8   7   4   2   1   1   1   1    1 
 *
 *----------------------------------------------------------------------*/
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
int complex(int a, int b) {
            
StartTickCounter();
  while (a < 30) {
            
StopTickCounter();
            printf("complex::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
 
StartTickCounter();
    while (b < a) {
            
StopTickCounter();
            printf("complex::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
      if (b > 5){
            
StopTickCounter();
            printf("complex::bb8 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
        b = b * 3;
            
StopTickCounter();
            printf("complex::bb10 %u\r\n", GetTicks());
            ResetTickCounter();
      }
      else{
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
        b = b + 2;
            
StopTickCounter();
            printf("complex::bb12 %u\r\n", GetTicks());
            ResetTickCounter();
      }
            
StartTickCounter();
      if (b >= 10 && b <= 12){
            
StopTickCounter();
            printf("complex::bb14 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
        a = a + 10;
            
StopTickCounter();
            printf("complex::bb18 %u\r\n", GetTicks());
            ResetTickCounter();
      }
      else{
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
        a = a + 1;
            
StopTickCounter();
            printf("complex::bb20 %u\r\n", GetTicks());
            ResetTickCounter();
      }
            
StopTickCounter();
            ResetTickCounter();
            printf("complex::bb22 0\r\n");
            StartTickCounter();    }
            
StartTickCounter();
    a = a + 2;
    b = b - 10;
            
StopTickCounter();
            printf("complex::bb23 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
  }
            
  return 1;
}
int main() {
      stdout = &virtual_port;
  int a = 1, b = 1, answer = 0;
            
StartTickCounter();
  answer = complex(a, b);
  return answer;
}