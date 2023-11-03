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
long int a[10][10], b[10], x[10];
int ludcmp(int nmax, int n);
int main(){
  stdout = &virtual_port;
  int      i, j, nmax = 10, n = 5, chkerr;
  long int w;
  /* Init loop */
            
StartTickCounter();
  for(i = 0; i <= n; i++){
            
StopTickCounter();
            printf("main::bb1 %u\r\n", GetTicks());
            ResetTickCounter();
      w = 0.0;
            
StartTickCounter();
      for(j = 0; j <= n; j++){
            
StopTickCounter();
            printf("main::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
          a[i][j] = (i + 1) + (j + 1);
          if(i == j){
            
StopTickCounter();
            printf("main::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
            a[i][j] *= 2.0;
            
StopTickCounter();
            printf("main::bb13 %u\r\n", GetTicks());
            ResetTickCounter();
          } 
            
StartTickCounter();
          w += a[i][j];
            
StopTickCounter();
            ResetTickCounter();
            printf("main::bb21 0\r\n");
            StartTickCounter();        }
StopTickCounter();
ResetTickCounter();        
StartTickCounter();
      b[i] = w;
            
StopTickCounter();
            printf("main::bb29 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
    }
            
StartTickCounter();
  chkerr = ludcmp(nmax,n);
  return 0;
            
StopTickCounter();
            printf("main::bb34 %u\r\n", GetTicks());
            ResetTickCounter();
}
int ludcmp(int nmax, int n){
  int i, j, k;
  long w, y[100];
StopTickCounter();
ResetTickCounter();   
StartTickCounter();
  for(i = 0; i < n; i++){
            
StopTickCounter();
            printf("ludcmp::bb1 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
      for(j = i+1; j <= n; j++){
            
StopTickCounter();
            printf("ludcmp::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
          w = a[j][i];
          if(i != 0){
            
StopTickCounter();
            printf("ludcmp::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
            for(k = 0; k < i; k++){
            
StopTickCounter();
            printf("ludcmp::bb12 %u\r\n", GetTicks());
            ResetTickCounter();
            
	    StartTickCounter();
            w -= a[j][k] * a[k][i];
                      }
            
StopTickCounter();
            ResetTickCounter();
            printf("ludcmp::bb27 Line 37           } 0\r\n");
            StartTickCounter();          }            
         
         
         StopTickCounter();
         ResetTickCounter();  
StartTickCounter();
          a[j][i] = w / a[i][i];
            
StopTickCounter();
            printf("ludcmp::bb28 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
        }
StopTickCounter();
ResetTickCounter();    
StartTickCounter();
      for(j = i+1; j <= n; j++){
            
StopTickCounter();
            printf("ludcmp::bb39 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
          w = a[i+1][j];
          
          StopTickCounter();
            printf("ludcmp::bb41 %u\r\n", GetTicks());
            ResetTickCounter();
          
          
          StartTickCounter();
          for(k = 0; k <= i; k++){
            
          StopTickCounter();
            printf("ludcmp::bb47 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
StartTickCounter();
            w -= a[i+1][k] * a[k][j];
            
StopTickCounter();
            printf("ludcmp::bb50 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
       	}
         StopTickCounter();
         ResetTickCounter();  
StartTickCounter();
          a[i+1][j] = w;
            
StopTickCounter();
            printf("ludcmp::bb63 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
        }
            
StopTickCounter();
            ResetTickCounter();
            printf("ludcmp::bb69 0\r\n");
            StartTickCounter();    }
            
StartTickCounter();
  y[0] = b[0];
  
             StopTickCounter();
            printf("ludcmp::bb72 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
            StartTickCounter();
            
  for(i = 1; i <= n; i++){
             StopTickCounter();
            printf("ludcmp::bb75 %u\r\n", GetTicks());
            ResetTickCounter();
StartTickCounter();
      w = b[i];
      
      StopTickCounter();
            printf("ludcmp::bb77 %u\r\n", GetTicks());
            ResetTickCounter();
      
      
      StartTickCounter();
      
      for(j = 0; j < i; j++){
            
      StopTickCounter();
            printf("ludcmp::bb81 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
StartTickCounter();
        w -= a[i][j] * y[j];
                 }
        
         StopTickCounter();
         ResetTickCounter();  
StartTickCounter();
      y[i] = w;
            
StopTickCounter();
            printf("ludcmp::bb95 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
    }
    StopTickCounter();
    ResetTickCounter();       
StartTickCounter();
  x[n] = y[n] / a[n][n];
  
             StopTickCounter();
            printf("ludcmp::bb100 %u\r\n", GetTicks());
            ResetTickCounter();
            
       StartTickCounter();     
            
  for(i = n-1; i >= 0; i--){
            
            StopTickCounter();
            printf("ludcmp::bb111 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
StartTickCounter();
      w = y[i];
      StopTickCounter();
            printf("ludcmp::bb113 %u\r\n", GetTicks());
            ResetTickCounter();
      
      
      StartTickCounter();
      
      
      for(j = i+1; j <= n; j++){
            
StopTickCounter();
            printf("ludcmp::bb117 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
StartTickCounter();
        w -= a[i][j] * x[j];
            
     } 
StopTickCounter();
ResetTickCounter();     
StartTickCounter();
      x[i] = w / a[i][i];
            
StopTickCounter();
            printf("ludcmp::bb131 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
  }
            
StartTickCounter();
  return(0);
            
StopTickCounter();
            printf("ludcmp::bb140 %u\r\n", GetTicks());
            ResetTickCounter();
}