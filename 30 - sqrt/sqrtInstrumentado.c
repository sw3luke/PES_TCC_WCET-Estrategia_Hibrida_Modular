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
float fabs2(float x){
 StopTickCounter();
 ResetTickCounter();
 StartTickCounter();
 
   if (x < 0){
            
StopTickCounter();
            printf("fabs2::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
      return -x;
            
StopTickCounter();
            printf("fabs2::bb1 %u\r\n", GetTicks());
            ResetTickCounter();
   }
      
   else{
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
      return x;
            
StopTickCounter();
            printf("fabs2::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
   }
      
            
StopTickCounter();
            ResetTickCounter();
            printf("fabs2::bb4 Line 10 } 0\r\n");
            StartTickCounter();}
float sqrtfcn(int valor){
            
StartTickCounter();
   float val = (float)valor;
StopTickCounter();
printf("sqrtfcn::bb0:1 %u\r\n", GetTicks());
ResetTickCounter();
StartTickCounter();
   float x = val/10;
StopTickCounter();
printf("sqrtfcn::bb3:1 %u\r\n", GetTicks());
ResetTickCounter();
StartTickCounter();
   float dx;
   double diff;
   double min_tol = 0.00001;
   int i, flag;
   flag = 0;
   if (val == 0 ){
            
StopTickCounter();
            printf("sqrtfcn::bb0:2 %u\r\n", GetTicks());
            ResetTickCounter();
      x = 0;
      
StopTickCounter();
            ResetTickCounter();
            printf("sqrtfcn::bb2 0\r\n");
            StartTickCounter();   }
   else {
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
      for (i=1;i<20;i++){
            
StopTickCounter();
            printf("sqrtfcn::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
StartTickCounter();
         if (!flag) {
            
StopTickCounter();
            printf("sqrtfcn::bb7 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
            
            StartTickCounter();
            dx = (val - (x*x)) / (2.0 * x);
            x = x + dx;
            diff = val - (x*x);
            if (fabs2(diff) <= min_tol){
            
StopTickCounter();
            printf("sqrtfcn::bb9 %u\r\n", GetTicks());
            ResetTickCounter();
               flag = 1;
            
StopTickCounter();
            ResetTickCounter();
            printf("sqrtfcn::bb23 0\r\n");
            StartTickCounter();            }
               
            
StopTickCounter();
            ResetTickCounter();
            printf("sqrtfcn::bb24 0\r\n");
            StartTickCounter();         }
            
StopTickCounter();
            ResetTickCounter();
            printf("sqrtfcn::bb25 0\r\n");
            StartTickCounter();      }
   }
            
   return (x);
}
int main(){
	stdout = &virtual_port;
	int valor = 0;
	sqrtfcn(valor);
}