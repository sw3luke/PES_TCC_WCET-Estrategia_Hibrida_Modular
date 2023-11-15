#include "soc_AM335x.h"
#include "beaglebone.h"

#define PI 3.14159
#define M_PI 3.14159

//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 


double ar[8];
double ai[8] = {0.,  };

int fft1(int n, int flag);


static double fabs(double n)
{
  double f;

  if (n >= 0) f = n;
  else f = -n;
  return f;
}

static double log(double n)
{
  return(4.5);
}


static double sin(rad)
double rad;
{
  double app;

  double diff;
  int inc = 1;

  while (rad > 2*PI)
	rad -= 2*PI;
  while (rad < -2*PI)
    rad += 2*PI;
  app = diff = rad;
   diff = (diff * (-(rad*rad))) /
      ((2.0 * inc) * (2.0 * inc + 1.0));
    app = app + diff;
    inc++;
  while(fabs(diff) >= 0.00001) {
    diff = (diff * (-(rad*rad))) /
      ((2.0 * inc) * (2.0 * inc + 1.0));
    app = app + diff;
    inc++;
  }

  return(app);
}


static double cos(double rad)
{

  return (sin (PI / 2.0 - rad));
}


int main()
{
/* ------------------- Debug de conferencia de registradores -------------------*/

/*

//====================== Hardware Instrumentation Definitions ======================

    unsigned int anotherControlRegister;
    unsigned int* newRegisterCheck = (unsigned int*)0x8009af70;
    unsigned int current_mode;
    unsigned int* currentModeStatus = (unsigned int*)0x8009af80;
    unsigned int auxiliaryControlRegister;
    unsigned int* addrAuxiliaryControlRegisterBefore = (unsigned int*)0x8009af90;


//====================== Hardware Instrumentation Definitions ======================
    
    
    asm volatile("MRC p15, 0, %0, c1, c0, 0\t\n": "=r"(anotherControlRegister)); 
    *newRegisterCheck = anotherControlRegister; 
    
    asm volatile("MRS %0, CPSR" : "=r"(current_mode));
    *currentModeStatus = current_mode;//current_mode;
    
    asm volatile("MRC p15, 0, %0, c1, c0, 1\t\n": "=r"(auxiliaryControlRegister));
    *addrAuxiliaryControlRegisterBefore = auxiliaryControlRegister;
 
*/

    init_perfcounters (1, 0);
    unsigned int numCycles = 0;
    unsigned int overhead = get_cyclecount();

    overhead = get_cyclecount() - overhead;
    unsigned int t = 0;
    unsigned int* addr = (unsigned int*)0x80069FF0;

    init_cache_garbage_array();
    int numberExecutions;
    for(numberExecutions = 0; numberExecutions < 50000; numberExecutions++){
	t = get_cyclecount();
	//====================== Target Flow ======================
	int  i, n = 8, flag, chkerr;


	/* ar  */
	for(i = 0; i < n; i++)
	  ar[i] = cos(2*M_PI*i/n);

	/* forward fft */
	flag = 0;
	chkerr = fft1(n, flag);

	/* inverse fft */
	flag = 1;
	chkerr = fft1(n, flag);

	//====================== Target Flow ======================
	
	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(numberExecutions)) = numCycles;
	cache_maintenance();
    } 

	return 0;
}



int fft1(int n, int flag)
{

	 int i, j, k, it, xp, xp2, j1, j2, iter;
	 double sign, w, wr, wi, dr1, dr2, di1, di2, tr, ti, arg;

	 if(n < 2) return(999);
	 iter = log((double)n)/log(2.0);
	 j = 1;
	 for(i = 0; i < iter; i++)
	   j *= 2;
	 if(fabs(n-j) > 1.0e-6)
	   return(1);

	 /*  Main FFT Loops  */
	 sign = ((flag == 1) ? 1.0 : -1.0);
	 xp2 = n;
	 for(it = 0; it < iter; it++)
	 {
			 xp = xp2;
			 xp2 /= 2;
			 w = PI / xp2;
			 for(k = 0; k < xp2; k++)
			 {
					 arg = k * w;
					 wr = cos(arg);
					 wi = sign * sin(arg);
					 i = k - xp;
					 for(j = xp; j <= n; j += xp)
					 {
							 j1 = j + i;
							 j2 = j1 + xp2;
							 dr1 = ar[j1];
							 dr2 = ar[j2];
							 di1 = ai[j1];
							 di2 = ai[j2];
							 tr = dr1 - dr2;
							 ti = di1 - di2;
							 ar[j1] = dr1 + dr2;
							 ai[j1] = di1 + di2;
							 ar[j2] = tr * wr - ti * wi;
							 ai[j2] = ti * wr + tr * wi;
					 }
			 }
	 }

	 /*  Digit Reverse Counter  */

	 j1 = n / 2;
	 j2 = n - 1;
	 j = 1;

	 for(i = 1; i <= j2; i++)
	 {
			 if(i < j)
			 {
					tr = ar[j-1];
					ti = ai[j-1];
					ar[j-1] = ar[i-1];
					ai[j-1] = ai[i-1];
					ar[i-1] = tr;
					ai[i-1] = ti;
			 }
			 k = j1;
			 while(k < j)
			 {
					j -= k;
					k /= 2;
			 }
			 j += k;
	 }
	 if(flag == 0) return(0);
	 w = n;
	 for(i = 0; i < n; i++)
	 {
			 ar[i] /= w;
			 ai[i] /= w;
	 }
	 return(0);
}


//============================== Hardware Measure Routine ==============================


static inline unsigned int get_cyclecount (void){
  unsigned int value;
  // Read CCNT Register
  asm volatile ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(value));
  //Referencia do registrador na documentacao pode ser encontrada no link abaixo
  /*https://developer.arm.com/documentation/ddi0344/k/system-control-coprocessor/system-control-coprocessor-registers/c9--cycle-count-register?lang=en*/
  return value;
}



static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider){
  // in general enable all counters (including cycle counter)
  int32_t value = 1;

  // peform reset:  
  if (do_reset)
  {
    value |= 2;     // resetar todos os contadores para zero.
    value |= 4;     // resetar contadores de ciclo para zero.
  } 

  if (enable_divider)
    value |= 8;     // enable "by 64" divider for CCNT.

  value |= 16;

  // program the performance-counter control-register:
  asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(value));  

  // enable all counters:  
  asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));  

  // clear overflows:
  asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
}



void init_cache_garbage_array(){

	int* garbage_array_addr = (int*)0x80000ba0; 
	int i;
	for(i = 0; i < 8192; i++){
		*(garbage_array_addr+(i*4)) = 0; //um equivalente de j = j+1 para cada posicao do array
		
	}

}


void cache_maintenance(){
	
	//Sintaxe do comando MCR:
	//MCR<c> <coproc>,<opc1>,<Rt>,<CRn>,<CRm>{,<opc2>}
	//Rt -> valor a ser escrito no registrador do coprocessador
	//CRn -> registrador que recebera o valor
	//CRm -> registrador de destino adicional
	//opc2 -> opcode, se nao definido sera 0
	
	
	asm volatile("MCR p15, 0, %0, c7, c5, 0" :: "r"(0));//invalida conteudo da cache de instrucoes
	
	
	int* garbage_array_addr = (int*)0x80000ba0;
	int i;
	for(i = 0; i < 8192; i++){
		*(garbage_array_addr+(i*4)) = *(garbage_array_addr+(i*4)) + 1; //um equivalente de j = j+1 para cada posicao do array
	}
}


//============================== Hardware Measure Routine ==============================


