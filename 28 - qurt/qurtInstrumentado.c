#include <avr/io.h>
bb4#include <stdio.h>
bb4#include "avr-tick-counter.h"
bb4bb4bb4bb4bb4#define special_output_port (*((volatile char *)0x20))
bb4bb4bb4int virtual_putchar(char c, FILE *unused)
bb4{
bb4    special_output_port = c;
bb4    return 0;
bb4}
bb4bb4bb4bb4bb4 FILE virtual_port = FDEV_SETUP_STREAM(virtual_putchar, NULL, _FDEV_SETUP_WRITE);
bb4bb4bb4double a[3], x1[2], x2[2];
bb4int flag;
bb4bb4bb4int  qurt();
bb4bb4bb4bb4bb4double qurt_fabs(double n){
bb4  double f;
bb4bb4bb4bb4bb4StopTickCounter();
bb4ResetTickCounter();
bb4StartTickCounter();
bb4  if (n >= 0){
bb4  	f = n;
bb4  	StopTickCounter();
bb4            printf("qurt_fabs::bb0 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4  }
bb4bb4bb4  else{
bb4  	StopTickCounter();
bb4  	ResetTickCounter();
bb4  	StartTickCounter();
bb4  	f = -n;
bb4  	StopTickCounter();
bb4            printf("qurt_fabs::bb2 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4  }
bb4            
bb4bb4bb4                
bb4StopTickCounter();
bb4                ResetTickCounter();
bb4                StartTickCounter();
bb4  return f;
bb4            
bb4StopTickCounter();
bb4            printf("qurt_fabs::bb4 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4}
bb4bb4bb4double qurt_sqrt(val)
bb4double val;
bb4{
bb4StopTickCounter();
bb4ResetTickCounter();
bb4StartTickCounter();    
bb4  double x = val/10;
bb4bb4bb4StopTickCounter();
bb4            printf("qurt_sqrt::bb2:1 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4bb4bb4  double dx;
bb4bb4bb4  double diff;
bb4  double min_tol = 0.00001;
bb4bb4bb4  int i, flag;
bb4bb4bb4  flag = 0;
bb4            
bb4StartTickCounter();
bb4  if (val == 0 ){
bb4            
bb4bb4bb4	x = 0;
bb4            StopTickCounter();
bb4            printf("qurt_sqrt::bb0 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4             }
bb4  else {
bb4                
bb4StopTickCounter();
bb4                ResetTickCounter();
bb4                StartTickCounter();
bb4    for (i=1;i<20;i++){
bb4            
bb4StopTickCounter();
bb4            printf("qurt_sqrt::bb4 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4            
bb4StartTickCounter();
bb4		if (!flag) {
bb4            
bb4StopTickCounter();
bb4            printf("qurt_sqrt::bb6 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4			
bb4			
bb4			
bb4StartTickCounter();
bb4			dx = (val - (x*x)) / (2.0 * x);
bb4			x = x + dx;
bb4			diff = val - (x*x);
bb4			if (qurt_fabs(diff) <= min_tol){
bb4            			flag = 1;
bb4StopTickCounter();
bb4            printf("qurt_sqrt::bb8 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4				
bb4            
bb4StopTickCounter();
bb4            ResetTickCounter();
bb4            printf("qurt_sqrt::bb18 0\r\n");
bb4            StartTickCounter();			}
bb4            
bb4StopTickCounter();
bb4            ResetTickCounter();
bb4            printf("qurt_sqrt::bb19 0\r\n");
bb4            StartTickCounter();		}
bb4            
bb4StopTickCounter();
bb4            ResetTickCounter();
bb4            printf("qurt_sqrt::bb20 0\r\n");
bb4            StartTickCounter();    }
bb4  }
bb4            
bb4StartTickCounter();
bb4  return (x);
bb4            
bb4StopTickCounter();
bb4            printf("qurt_sqrt::bb24 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4}
bb4bb4bb4void preencheArray(int v,int b, int c){
bb4bb4bb4            
bb4StartTickCounter();
bb4	a[0] =  (double)v;
bb4	a[1] =  (double)b;
bb4	a[2] =  (double)c;
bb4bb4bb4            
bb4StopTickCounter();
bb4            printf("preencheArray::bb0 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4}
bb4bb4bb4int main(){
bb4bb4bb4	int v,b,c;
bb4	stdout = &virtual_port;
bb4            
bb4StartTickCounter();
bb4	
bb4	/*preencheArray(v,b,c);*/
bb4	
bb4	
bb4	a[0] =  1.0;
bb4	a[1] = -3.0;
bb4	a[2] =  2.0;
bb4bb4bb4	qurt();
bb4bb4bb4  return 0;
bb4bb4bb4}
bb4bb4bb4int  qurt(){
bb4	double  d, w1, w2;
bb4bb4bb4   StopTickCounter();  
bb4   ResetTickCounter();       
bb4StartTickCounter();
bb4	if(a[0] == 0.0) {
bb4            
bb4StopTickCounter();
bb4            printf("qurt::bb0 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4            
bb4		return(999);
bb4	}
bb4StopTickCounter(); 
bb4ResetTickCounter(); 
bb4      
bb4StartTickCounter();
bb4	d = a[1]*a[1] - 4 * a[0] * a[2];
bb4	w1 = 2.0 * a[0];
bb4            
bb4bb4bb4	w2 = qurt_sqrt(qurt_fabs(d));
bb4	StopTickCounter(); 
bb4ResetTickCounter(); 
bb4      
bb4StartTickCounter();
bb4	if(d > 0.0){
bb4            StopTickCounter();
bb4            printf("qurt::bb3 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4            
bb4            
bb4StartTickCounter();
bb4		 flag = 1;
bb4		 x1[0] = (-a[1] + w2) / w1;
bb4		 x1[1] = 0.0;
bb4		 x2[0] = (-a[1] - w2) / w1;
bb4		 x2[1] = 0.0;
bb4		 
bb4		 
bb4		 StopTickCounter();
bb4            printf("qurt::bb15 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4		 return(0);
bb4	}
bb4	else if(d == 0.0){
bb4            
bb4StopTickCounter();
bb4            printf("qurt::bb23 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4                
bb4         StartTickCounter();
bb4         
bb4		 flag = 0;
bb4		 x1[0] = -a[1] / w1;
bb4		 x1[1] = 0.0;
bb4		 x2[0] = x1[0];
bb4		 x2[1] = 0.0;
bb4		 
bb4		 
bb4	StopTickCounter();
bb4            printf("qurt::bb25 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4		 return(0);
bb4            
bb4bb4bb4	}
bb4	else{
bb4                
bb4StopTickCounter();
bb4                ResetTickCounter();
bb4                StartTickCounter();
bb4		 flag = -1;
bb4		 w2 /= w1;
bb4		 x1[0] = -a[1] / w1;
bb4		 x1[1] = w2;
bb4		 x2[0] = x1[0];
bb4		 x2[1] = -w2;
bb4		 
bb4		 StopTickCounter();
bb4            printf("qurt::bb30 %u\r\n", GetTicks());
bb4            ResetTickCounter();
bb4		 return(0);
bb4	}
bb4            
bb4StopTickCounter();
bb4            ResetTickCounter();
bb4            printf("qurt::bb37 0\r\n");
bb4            StartTickCounter();}
bb4