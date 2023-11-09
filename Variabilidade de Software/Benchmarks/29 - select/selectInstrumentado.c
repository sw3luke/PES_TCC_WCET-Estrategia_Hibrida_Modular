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







float select(unsigned long k, unsigned long n);



#define SWAP(a,b) temp=(a);(a)=(b);(b)=temp;



float arr[20] = {

	5, 4, 10.3, 1.1, 5.7, 100, 231, 111, 49.5, 99,

	10, 150, 222.22, 101, 77, 44, 35, 20.54, 99.99, 888.88

};





float 

select(unsigned long k, unsigned long n)

{

	unsigned long   i, ir, j, l, mid;

	float           a, temp;

	int             flag, flag2;



	l = 0;

          

          

           StopTickCounter();  

           ResetTickCounter();

StartTickCounter();

	ir = n - 1;

	flag = 0;

 

 

 StopTickCounter();

            printf("select::bb0 %u\r\n", GetTicks());

            ResetTickCounter();

 

StartTickCounter();

	while (!flag) {

            



            

StopTickCounter();

            printf("select::bb1 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

		if (ir <= l + 1) {

            

StopTickCounter();

            printf("select::bb3 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

			if (ir == l + 1) {

            

StopTickCounter();

            printf("select::bb6 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

				if (arr[ir] < arr[l]) {

            

StopTickCounter();

            printf("select::bb9 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

					SWAP(arr[l], arr[ir])

            

StopTickCounter();

            printf("select::bb15 %u\r\n", GetTicks());

            ResetTickCounter();

				}

            

StopTickCounter();

            ResetTickCounter();

            printf("select::bb22 Line 27 			} 0\r\n");

            StartTickCounter();			}

			flag = 1;

           

StartTickCounter();

		}

		

	else if (!flag) {

            

StopTickCounter();

            printf("select::bb23 %u\r\n", GetTicks());

            ResetTickCounter();

                

StopTickCounter();

                ResetTickCounter();

                StartTickCounter();

			mid = (l + ir) >> 1;

			SWAP(arr[mid], arr[l + 1])

            



			if (arr[l + 1] > arr[ir]) {

            StopTickCounter();

            printf("select::bb26 %u\r\n", GetTicks());

            ResetTickCounter();

StartTickCounter();

				SWAP(arr[l + 1], arr[ir])

            

StopTickCounter();

            printf("select::bb43 %u\r\n", GetTicks());

            ResetTickCounter();

			}

			

			ResetTickCounter();

           StopTickCounter(); 

StartTickCounter();

			if (arr[l] > arr[ir]) {

            

StopTickCounter();

            printf("select::bb52 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

				SWAP(arr[l], arr[ir])

            

StopTickCounter();

            printf("select::bb58 %u\r\n", GetTicks());

            ResetTickCounter();

			}

      StopTickCounter(); 

      ResetTickCounter();     

StartTickCounter();

			if (arr[l + 1] > arr[l]) {

            

StopTickCounter();

            printf("select::bb65 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

				SWAP(arr[l + 1], arr[l])

            

StopTickCounter();

            printf("select::bb72 %u\r\n", GetTicks());

            ResetTickCounter();

			}

           StopTickCounter(); 

           ResetTickCounter();

StartTickCounter();

			i = l + 1;

			j = ir;

			a = arr[l];

			flag2 = 0;

            StopTickCounter();

            printf("select::bb81 %u\r\n", GetTicks());

            ResetTickCounter();

            

            

StartTickCounter();

			while (!flag2) {

            

            StopTickCounter();

            printf("select::bb85 %u\r\n", GetTicks());

            ResetTickCounter();

            

            

StartTickCounter();

				i++;

				while (arr[i] < a){

            

StopTickCounter();

            printf("select::bb88 %u\r\n", GetTicks());

            ResetTickCounter();

            StartTickCounter();

					i++;

			}

            StopTickCounter();

            ResetTickCounter();

StartTickCounter();

				j--;

				while (arr[j] > a){

            



            

StopTickCounter();

            printf("select::bb94 %u\r\n", GetTicks());

            ResetTickCounter();

            StartTickCounter();

					j--;

								}

           StopTickCounter(); 

           ResetTickCounter();

StartTickCounter();

				if (j < i){

            

StopTickCounter();

            printf("select::bb99 %u\r\n", GetTicks());

            ResetTickCounter();

					flag2 = 1;

            

StopTickCounter();

            ResetTickCounter();

            printf("select::bb101 0\r\n");

            StartTickCounter();				}





StopTickCounter();

            ResetTickCounter();       

StartTickCounter();

				if (!flag2) {

            

StopTickCounter();

            printf("select::bb102 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

					SWAP(arr[i], arr[j])

            

StopTickCounter();

            printf("select::bb104 %u\r\n", GetTicks());

            ResetTickCounter();

				}

            

StopTickCounter();

            ResetTickCounter();

            printf("select::bb111 0\r\n");

            StartTickCounter();			}

            

            

            StopTickCounter();

            ResetTickCounter();

StartTickCounter();

			arr[l] = arr[j];

			arr[j] = a;

			if (j >= k){

            

StopTickCounter();

            printf("select::bb112 %u\r\n", GetTicks());

            ResetTickCounter();

            

StartTickCounter();

				ir = j - 1;

            

StopTickCounter();

            printf("select::bb118 %u\r\n", GetTicks());

            ResetTickCounter();

			}

            StopTickCounter();

            ResetTickCounter();

StartTickCounter();

			if (j <= k){

            

StopTickCounter();

            printf("select::bb120 %u\r\n", GetTicks());

            ResetTickCounter();

				l = i;

            

StopTickCounter();

            ResetTickCounter();

            printf("select::bb122 0\r\n");

            StartTickCounter();			}			

            

StopTickCounter();

            ResetTickCounter();

            printf("select::bb123 0\r\n");

            StartTickCounter();		}

            

StopTickCounter();

            ResetTickCounter();

            printf("select::bb125 0\r\n");

            StartTickCounter();	}

            

StartTickCounter();

	return arr[k];

            

StopTickCounter();

            printf("select::bb126 %u\r\n", GetTicks());

            ResetTickCounter();

}



int 

main(void)

{

           stdout = &virtual_port; 

	select(10, 2);

	return 0;

}