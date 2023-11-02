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
double          a[10][10], b[10], x[10];
int             ludcmp( /* int nmax, */ int n, double eps);
static double 
fabs(double n)
{
	double          f;
       StopTickCounter();  
       ResetTickCounter();   
StartTickCounter();
	if (n >= 0){
            
StopTickCounter();
            printf("fabs::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
		f = n;
            
StopTickCounter();
            ResetTickCounter();
            printf("fabs::bb1 0\r\n");
            	}
	else{
                
StopTickCounter();
                ResetTickCounter();
                StartTickCounter();
		f = -n;
            
StopTickCounter();
            printf("fabs::bb2 %u\r\n", GetTicks());
            ResetTickCounter();
	}
            
StartTickCounter();
	return f;
            
StopTickCounter();
            printf("fabs::bb4 %u\r\n", GetTicks());
            ResetTickCounter();
}
int 
main(void)
{
	int             i, j/*, nmax = 50*/, n = 5, chkerr;
	double          eps, w;
	eps = 1.0e-6;
stdout = &virtual_port;            
StartTickCounter();
	for (i = 0; i <= n; i++) {
            
StopTickCounter();
            printf("main::bb1 %u\r\n", GetTicks());
            ResetTickCounter();
		w = 0.0;
            
StartTickCounter();
		for (j = 0; j <= n; j++) {
            
StopTickCounter();
            printf("main::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
			a[i][j] = (i + 1) + (j + 1);
			if (i == j){
            
StopTickCounter();
            printf("main::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
				a[i][j] *= 10.0;
            
StopTickCounter();
            printf("main::bb13 %u\r\n", GetTicks());
            ResetTickCounter();
			}
       StopTickCounter();  
       ResetTickCounter();   
StartTickCounter();
			w += a[i][j];
            }
            StopTickCounter();  
       ResetTickCounter();       
StartTickCounter();
		b[i] = w;
            
StopTickCounter();
            printf("main::bb27 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
	}
	chkerr = ludcmp( /* nmax, */ n, eps);
	return 0;
}
int 
ludcmp( /* int nmax, */ int n, double eps)
{
	int             i, j, k;
	double          w, y[100];
  StopTickCounter();   
  ResetTickCounter();       
StartTickCounter();
	if (n > 99 || eps <= 0.0){
            
StopTickCounter();
            printf("ludcmp::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
		return (999);
            
StopTickCounter();
            printf("ludcmp::bb3 %u\r\n", GetTicks());
            ResetTickCounter();
	}
       StopTickCounter();   
  ResetTickCounter();         
StartTickCounter();
	for (i = 0; i < n; i++) {
            
StopTickCounter();
            printf("ludcmp::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
		if (fabs(a[i][i]) <= eps){
            
StopTickCounter();
            printf("ludcmp::bb7 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
			return (1);
            
StopTickCounter();
            printf("ludcmp::bb14 %u\r\n", GetTicks());
            ResetTickCounter();
		}
      StopTickCounter();  
      ResetTickCounter();    
StartTickCounter();
		for (j = i + 1; j <= n; j++) {
            
StopTickCounter();
            printf("ludcmp::bb16 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
			w = a[j][i];
			if (i != 0){
            
StopTickCounter();
            printf("ludcmp::bb18 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
				for (k = 0; k < i; k++){
            
StopTickCounter();
            printf("ludcmp::bb25 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
					w -= a[j][k] * a[k][i];
            			}
            
StopTickCounter();
            ResetTickCounter();
            printf("ludcmp::bb40 0\r\n");
            StartTickCounter();			}
StopTickCounter();
            ResetTickCounter();         
StartTickCounter();
			a[j][i] = w / a[i][i];
            
StopTickCounter();
            printf("ludcmp::bb41 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
		}
          StopTickCounter();  
          ResetTickCounter();
StartTickCounter();
		for (j = i + 1; j <= n; j++) {
            
StopTickCounter();
            printf("ludcmp::bb52 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
			w = a[i + 1][j];
			StopTickCounter();
            printf("ludcmp::bb54 %u\r\n", GetTicks());
            ResetTickCounter();
            
            StartTickCounter();
			for (k = 0; k <= i; k++){
            
StopTickCounter();
            printf("ludcmp::bb60 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
				w -= a[i + 1][k] * a[k][j];
            		}
            StopTickCounter();
            ResetTickCounter();
StartTickCounter();
			a[i + 1][j] = w;
            
StopTickCounter();
            printf("ludcmp::bb76 %u\r\n", GetTicks());
            ResetTickCounter();
            StartTickCounter();
		}
            
StopTickCounter();
            ResetTickCounter();
            printf("ludcmp::bb82 0\r\n");
            StartTickCounter();	}
    
    
    StopTickCounter();     
    ResetTickCounter();   
StartTickCounter();
	y[0] = b[0];
	
StopTickCounter();
            printf("ludcmp::bb85 %u\r\n", GetTicks());
            ResetTickCounter();
            
            StartTickCounter();
	for (i = 1; i <= n; i++) {
            
            
StopTickCounter();
            printf("ludcmp::bb88 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
		w = b[i];
            
            StopTickCounter();
            printf("ludcmp::bb90 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
		for (j = 0; j < i; j++){
            
StopTickCounter();
            printf("ludcmp::bb94 %u\r\n", GetTicks());
            ResetTickCounter();
StartTickCounter();
			w -= a[i][j] * y[j];
	
	}
         StopTickCounter();   
         ResetTickCounter();
StartTickCounter();
		y[i] = w;
            
StopTickCounter();
            printf("ludcmp::bb108 %u\r\n", GetTicks());
            ResetTickCounter();
            
            StartTickCounter();
	}
                   StopTickCounter();   
         ResetTickCounter();  
StartTickCounter();
	x[n] = y[n] / a[n][n];
            
StopTickCounter();
            printf("ludcmp::bb113 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
	for (i = n - 1; i >= 0; i--) {
            
StopTickCounter();
            printf("ludcmp::bb124 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
		w = y[i];
            
StopTickCounter();
            printf("ludcmp::bb126 %u\r\n", GetTicks());
            ResetTickCounter();
            
            
StartTickCounter();
		for (j = i + 1; j <= n; j++){
            
            
StopTickCounter();
            printf("ludcmp::bb130 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
			w -= a[i][j] * x[j];
            }
            
            
            StopTickCounter();
            ResetTickCounter();
StartTickCounter();
		x[i] = w / a[i][i];
            
StopTickCounter();
            printf("ludcmp::bb144 %u\r\n", GetTicks());
            ResetTickCounter();
            
            StartTickCounter();
	}
            
StartTickCounter();
	return (0);
            
StopTickCounter();
            printf("ludcmp::bb153 %u\r\n", GetTicks());
            ResetTickCounter();
            
StopTickCounter();
            ResetTickCounter();
            printf("ludcmp::bb154 0\r\n");
            StartTickCounter();}