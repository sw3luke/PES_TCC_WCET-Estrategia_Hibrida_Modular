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
double a[3], x1[2], x2[2];
int flag;
int  qurt();
double qurt_fabs(double n){
  double f;
StopTickCounter();
ResetTickCounter();
StartTickCounter();
  if (n >= 0){
  	f = n;
  	StopTickCounter();
            printf("qurt_fabs::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
  }
  else{
  	StopTickCounter();
  	ResetTickCounter();
  	StartTickCounter();
  	f = -n;
  	StopTickCounter();
            printf("qurt_fabs::bb2 %u\r\n", GetTicks());
            ResetTickCounter();
  }
            
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
  return f;
            
StopTickCounter();
            printf("qurt_fabs::bb4 %u\r\n", GetTicks());
            ResetTickCounter();
}
double qurt_sqrt(val)
double val;
{
StopTickCounter();
ResetTickCounter();
StartTickCounter();    
  double x = val/10;
StopTickCounter();
            printf("qurt_sqrt::bb2:1 %u\r\n", GetTicks());
            ResetTickCounter();
  double dx;
  double diff;
  double min_tol = 0.00001;
  int i, flag;
  flag = 0;
            
StartTickCounter();
  if (val == 0 ){
            
	x = 0;
            StopTickCounter();
            printf("qurt_sqrt::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
             }
  else {
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
    for (i=1;i<20;i++){
            
StopTickCounter();
            printf("qurt_sqrt::bb2:2 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
		if (!flag) {
            
StopTickCounter();
            printf("qurt_sqrt::bb6 %u\r\n", GetTicks());
            ResetTickCounter();
			
			
			
StartTickCounter();
			dx = (val - (x*x)) / (2.0 * x);
			x = x + dx;
			diff = val - (x*x);
			if (qurt_fabs(diff) <= min_tol){
            			flag = 1;
StopTickCounter();
            printf("qurt_sqrt::bb8 %u\r\n", GetTicks());
            ResetTickCounter();
				
            
StopTickCounter();
            ResetTickCounter();
            printf("qurt_sqrt::bb18 0\r\n");
            StartTickCounter();			}
            
StopTickCounter();
            ResetTickCounter();
            printf("qurt_sqrt::bb19 0\r\n");
            StartTickCounter();		}
            
StopTickCounter();
            ResetTickCounter();
            printf("qurt_sqrt::bb20 0\r\n");
            StartTickCounter();    }
  }
            
StartTickCounter();
  return (x);
            
StopTickCounter();
            printf("qurt_sqrt::bb24 %u\r\n", GetTicks());
            ResetTickCounter();
}
void preencheArray(int v,int b, int c){
            
StartTickCounter();
	a[0] =  (double)v;
	a[1] =  (double)b;
	a[2] =  (double)c;
            
StopTickCounter();
            printf("preencheArray::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
}
int main(){
	int v,b,c;
	stdout = &virtual_port;
            
StartTickCounter();
	
	/*preencheArray(v,b,c);*/
	
	
	a[0] =  1.0;
	a[1] = -3.0;
	a[2] =  2.0;
	qurt();
  return 0;
}
int  qurt(){
	double  d, w1, w2;
   StopTickCounter();  
   ResetTickCounter();       
StartTickCounter();
	if(a[0] == 0.0) {
            
StopTickCounter();
            printf("qurt::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
            
		return(999);
	}
StopTickCounter(); 
ResetTickCounter(); 
      
StartTickCounter();
	d = a[1]*a[1] - 4 * a[0] * a[2];
	w1 = 2.0 * a[0];
            
	w2 = qurt_sqrt(qurt_fabs(d));
	StopTickCounter(); 
ResetTickCounter(); 
      
StartTickCounter();
	if(d > 0.0){
            StopTickCounter();
            printf("qurt::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
StartTickCounter();
		 flag = 1;
		 x1[0] = (-a[1] + w2) / w1;
		 x1[1] = 0.0;
		 x2[0] = (-a[1] - w2) / w1;
		 x2[1] = 0.0;
		 
		 
		 StopTickCounter();
            printf("qurt::bb15 %u\r\n", GetTicks());
            ResetTickCounter();
		 return(0);
	}
	else if(d == 0.0){
            
StopTickCounter();
            printf("qurt::bb23 %u\r\n", GetTicks());
            ResetTickCounter();
                
         StartTickCounter();
         
		 flag = 0;
		 x1[0] = -a[1] / w1;
		 x1[1] = 0.0;
		 x2[0] = x1[0];
		 x2[1] = 0.0;
		 
		 
	StopTickCounter();
            printf("qurt::bb25 %u\r\n", GetTicks());
            ResetTickCounter();
		 return(0);
            
	}
	else{
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
		 flag = -1;
		 w2 /= w1;
		 x1[0] = -a[1] / w1;
		 x1[1] = w2;
		 x2[0] = x1[0];
		 x2[1] = -w2;
		 
		 StopTickCounter();
            printf("qurt::bb30 %u\r\n", GetTicks());
            ResetTickCounter();
		 return(0);
	}
            
StopTickCounter();
            ResetTickCounter();
            printf("qurt::bb37 0\r\n");
            StartTickCounter();}
