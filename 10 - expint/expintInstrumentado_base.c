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



long int expint(int n, long int x);







int main(void){

     stdout = &virtual_port;

     expint(50,2);

  return 0;

            

StopTickCounter();

            printf("main::bb0 %u\r\n", GetTicks());

            ResetTickCounter();

}



long int foo(long int x){

  return x*x+(8*x)<<4-x;

            

StopTickCounter();

            printf("expint::bb0 %u\r\n", GetTicks());

            ResetTickCounter();

}







/* Function with same flow, different data types,



   nonsensical calculations */



long int expint(int n, long int x){

  int      i,ii,nm1;

  long int a,b,c,d,del,fact,h,psi,ans=0;

            

StartTickCounter();

  nm1=n-1;                      /* arg=50 --> 49 */

  if(x>1){

            

StopTickCounter();

            printf("expint::bb0 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

      b=x+n;

      c=2e6;

      d=3e7;

      h=d;

            

      for (i=1;i<=100;i++){

            

StopTickCounter();

            printf("expint::bb2 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

          a = -i*(nm1+i);

          b += 2;

          d=10*(a*d+b);

            



          c=b+a/c;

          del=c*d;

          h *= del;

          if (del < 10000){

            StopTickCounter();

            printf("expint::bb7 %u\r\n", GetTicks());

            ResetTickCounter();

	    StartTickCounter();

            

            ans=h*-x;

            StopTickCounter();

            

            printf("expint::bb21 %u\r\n", GetTicks());

            ResetTickCounter();

              return ans;

            



          }

            

StopTickCounter();

            ResetTickCounter();

            printf("expint::bb24 0\r\n");

            StartTickCounter();        }

            

StopTickCounter();

            ResetTickCounter();

            printf("expint::bb27 0\r\n");

  }

  else{

                

StopTickCounter();

      ResetTickCounter();

      StartTickCounter();

      ans = nm1 != 0 ? 2 : 1000;

      fact=1;

            

      for (i=1;i<=100;i++){

            

StopTickCounter();

            printf("expint::bb28 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

          fact *= -x/i;

          if (i != nm1){

            

StopTickCounter();

            printf("expint::bb33 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

            del = -fact/(i-nm1);

            

StopTickCounter();

            printf("expint::bb39 %u\r\n", GetTicks());

            ResetTickCounter();

          }

          else{

              StopTickCounter();

              ResetTickCounter();

              StartTickCounter();

              

              psi = 0x00FF;

            



              for (ii=1;ii<=nm1;ii++){

            

StopTickCounter();

            printf("expint::bb44 %u\r\n", GetTicks());

            ResetTickCounter();

            

	    StartTickCounter();

              	

            psi += ii + nm1;

              	

              	

            StopTickCounter();

            printf("expint::bb48 %u\r\n", GetTicks());

            ResetTickCounter();

              	

            

	    StopTickCounter();

            ResetTickCounter();

            printf("expint::bb47 0\r\n");

            StartTickCounter();

	    }

            

            StopTickCounter();

            ResetTickCounter();

	    StartTickCounter();

            

            del=psi+fact*foo(x);

            

            StopTickCounter();

            printf("expint::bb53 %u\r\n", GetTicks());

            ResetTickCounter();

            }

            

StartTickCounter();

          ans += del;

          

StopTickCounter();

            ResetTickCounter();

            printf("expint::bb58 %u\r\n", GetTicks());

            printf("expint::bb57 0\r\n");

            StartTickCounter();        }

    }

            

StartTickCounter();

  return ans;

            

StopTickCounter();

            printf("expint::bb62 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

}