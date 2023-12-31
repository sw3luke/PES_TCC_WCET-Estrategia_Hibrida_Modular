#include "soc_AM335x.h"
#include "beaglebone.h"

//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 

#define RAND_MAX 32768
#define PI 3.14159265358979323846


/* function prototypes for fft and filter functions */

static float gaussian(void);

#define N 201
#define L 20            /* filter order, (length L+1) */

/* set convergence parameter */
float mu = 0.01;


int lms_rand()
{
  static unsigned long next = 1;

  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

static float lms_log(r)
float r;
{
  return 4.5;
}

static float lms_fabs(float n)
{
  float f;

  if (n >= 0) f = n;
  else f = -n;
  return f;
}

static float lms_sqrt(val)
float val;
{
  float x = val/10;

  float dx;

  double diff;
  double min_tol = 0.00001;

  int i, flag;

  flag = 0;
  if (val == 0 ) x = 0;
  else {
    for (i=1;i<20;i++)
      {
	if (!flag) {
	  dx = (val - (x*x)) / (2.0 * x);
	  x = x + dx;
	  diff = val - (x*x);
	  if (lms_fabs(diff) <= min_tol) flag = 1;
	}
	else { }         /* JG */
/*	  x =x; */
      }
  }
  return (x);
}


static float lms_sin(rad)
float rad;
{
  float app;

  float diff;
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
  while(lms_fabs(diff) >= 0.00001) {
    diff = (diff * (-(rad*rad))) /
      ((2.0 * inc) * (2.0 * inc + 1.0));
    app = app + diff;
    inc++;
  }

  return(app);
}

static float gaussian()
{
    static int ready = 0;       /* flag to indicated stored value */
    static float gstore;        /* place to store other value */
    static float rconst1 = (float)(2.0/RAND_MAX);
    static float rconst2 = (float)(RAND_MAX/2.0);
    float v1,v2,r,fac;
    float gaus;

/* make two numbers if none stored */
    if(ready == 0) {
            v1 = (float)lms_rand() - rconst2;
            v2 = (float)lms_rand() - rconst2;
            v1 *= rconst1;
            v2 *= rconst1;
            r = v1*v1 + v2*v2;
        while (r > 1.0f) {
            v1 = (float)lms_rand() - rconst2;
            v2 = (float)lms_rand() - rconst2;
            v1 *= rconst1;
            v2 *= rconst1;
            r = v1*v1 + v2*v2;
        }       /* make radius less than 1 */

/* remap v1 and v2 to two Gaussian numbers */
        fac = lms_sqrt(-2.0f*lms_log(r)/r);
        gstore = v1*fac;        /* store one */
        gaus = v2*fac;          /* return one */
        ready = 1;              /* set ready flag */
    }

    else {
        ready = 0;      /* reset ready flag for next pair */
        gaus = gstore;  /* return the stored one */
    }

    return(gaus);
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
    int* addr = (int*)0x80069FF0;
    init_cache_garbage_array();
    int i;
    for(i = 0; i < 50000; i++){
	
	t = get_cyclecount();
	//====================== Target Flow ======================
    	float lms(float,float,float *,int,float,float);
    	static float d[N],b[21];
    	float signal_amp,noise_amp,arg,x/*,y*/; /* JG */
    	int k;

	/* create signal plus noise */
    	signal_amp = lms_sqrt(2.0);
    	noise_amp = 0.2*lms_sqrt(12.0);
    	arg = 2.0*PI/20.0;
    	for(k = 0 ; k < N ; k++) {
    	    d[k] = signal_amp*lms_sin(arg*k) + noise_amp*gaussian();
    	}

	/* scale based on L */
   	 mu = 2.0*mu/(L+1);
	
    	x = 0.0;
    	for(k = 0 ; k < N ; k++) {
        	lms(x,d[k],b,L,mu,0.01);
	/* delay x one sample */
        	x = d[k];
    	}
	//====================== Target Flow ======================

	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(i))= numCycles; //*(addr+(i*4))= numCycles;
	cache_maintenance();
    }


    return 0;
}

float lms(float x,float d,float *b,int l,
                  float mu,float alpha)
{
    int ll;
    float e,mu_e,/*lms_const,*/y; /* JG */
    static float px[51];      /* max L = 50 */
    static float sigma = 2.0; /* start at 2 and update internally */

    px[0]=x;

/* calculate filter output */
    y=b[0]*px[0];
    for(ll = 1 ; ll <= l ; ll++)
        y=y+b[ll]*px[ll];

/* error signal */
    e=d-y;

/* update sigma */
    sigma=alpha*(px[0]*px[0])+(1-alpha)*sigma;
    mu_e=mu*e/sigma;

/* update coefficients */
    for(ll = 0 ; ll <= l ; ll++)
        b[ll]=b[ll]+mu_e*px[ll];
/* update history */
    for(ll = l ; ll >= 1 ; ll--)
        px[ll]=px[ll-1];

    return(y);
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


