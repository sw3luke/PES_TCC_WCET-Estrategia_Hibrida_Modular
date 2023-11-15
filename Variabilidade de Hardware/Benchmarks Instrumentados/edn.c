#include "soc_AM335x.h"
#include "beaglebone.h"

#define N 100
#define ORDER 50

//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 


void            vec_mpy1(short y[], const short x[], short scaler);
long int        mac(const short *a, const short *b, long int sqr, long int *sum);
void            fir(const short array1[], const short coeff[], long int output[]);
void            fir_no_red_ld(const short x[], const short h[], long int y[]);
long int        latsynth(short b[], const short k[], long int n, long int f);
void            iir1(const short *coefs, const short *input, long int *optr, long int *state);
long int        codebook(long int mask, long int bitchanged, long int numbasis, long int codeword, long int g, const short *d, short ddim, short theta);
void            jpegdct(short *d, short *r);

/************************************************************************
*	Simple vector multiply				*
************************************************************************/
void
vec_mpy1(short y[], const short x[], short scaler)
{
	long int        i;

	for (i = 0; i < 150; i++)
		y[i] += ((scaler * x[i]) >> 15);
}


/*****************************************************
*			Dot Product	      *
*****************************************************/
long int
mac(const short *a, const short *b, long int sqr, long int *sum)
{
	long int        i;
	long int        dotp = *sum;

	for (i = 0; i < 150; i++) {
		dotp += b[i] * a[i];
		sqr += b[i] * b[i];
	}

	*sum = dotp;
	return sqr;
}


/*****************************************************
*		FIR Filter		     *
*****************************************************/
void
fir(const short array1[], const short coeff[], long int output[])
{
	long int        i, j, sum;

	for (i = 0; i < N - ORDER; i++) {
		sum = 0;
		for (j = 0; j < ORDER; j++) {
			sum += array1[i + j] * coeff[j];
		}
		output[i] = sum >> 15;
	}
}

/****************************************************
*	FIR Filter with Redundant Load Elimination
						
By doing two outer loops simultaneously, you can potentially  reuse data (depending on the DSP architecture).
x and h  only  need to be loaded once, therefore reducing redundant loads.
This reduces memory bandwidth and power.
*****************************************************/
void
fir_no_red_ld(const short x[], const short h[], long int y[])
{
	long int        i, j;
	long int        sum0, sum1;
	short           x0, x1, h0, h1;
	for (j = 0; j < 100; j += 2) {
		sum0 = 0;
		sum1 = 0;
		x0 = x[j];
		for (i = 0; i < 32; i += 2) {
			x1 = x[j + i + 1];
			h0 = h[i];
			sum0 += x0 * h0;
			sum1 += x1 * h0;
			x0 = x[j + i + 2];
			h1 = h[i + 1];
			sum0 += x1 * h1;
			sum1 += x0 * h1;
		}
		y[j] = sum0 >> 15;
		y[j + 1] = sum1 >> 15;
	}
}

/*******************************************************
*	Lattice Synthesis	           *
* This function doesn't follow the typical DSP multiply two  vector operation, but it will point out the compiler's flexibility   ********************************************************/
long int
latsynth(short b[], const short k[], long int n, long int f)
{
	long int        i;

	f -= b[n - 1] * k[n - 1];
	for (i = n - 2; i >= 0; i--) {
		f -= b[i] * k[i];
		b[i + 1] = b[i] + ((k[i] * (f >> 16)) >> 16);
	}
	b[0] = f >> 16;
	return f;
}

/*****************************************************
*			IIR Filter		     *
*****************************************************/
void
iir1(const short *coefs, const short *input, long int *optr, long int *state)
{
	long int        x;
	long int        t;
	long int        n;

	x = input[0];
	for (n = 0; n < 50; n++) {
		t = x + ((coefs[2] * state[0] + coefs[3] * state[1]) >> 15);
		x = t + ((coefs[0] * state[0] + coefs[1] * state[1]) >> 15);
		state[1] = state[0];
		state[0] = t;
		coefs += 4;	/* point to next filter coefs  */
		state += 2;	/* point to next filter states */
	}
	*optr++ = x;
}

/*****************************************************
*	Vocoder Codebook Search 	     *
*****************************************************/
long int
codebook(long int mask, long int bitchanged, long int numbasis, long int codeword, long int g, const short *d, short ddim, short theta)
/*
 * dfm (mask=d  bitchanged=1 numbasis=17  codeword=e[0] , g=d, d=a, ddim=c,
 * theta =1
 */

{
	long int        j;
	long int        tmpMask;

	tmpMask = mask << 1;
	for (j = bitchanged + 1; j <= numbasis; j++) {



/*		
 * The following code is removed since it gave a memory access exception.
 * It is OK since the return value does not control the flow.
 * The loop always iterates a fixed number of times independent of the loop body.
 
    if (theta == !(!(codeword & tmpMask)))
			g += *(d + bitchanged * ddim + j);
		else
			g -= *(d + bitchanged * ddim + j);
		tmpMask <<= 1;
*/
	}
	return g;
}


/*****************************************************
*		JPEG Discrete Cosine Transform 		     *
*****************************************************/
void
jpegdct(short *d, short *r)
{
	long int        t[12];
	short           i, j, k, m, n, p;
	for (k = 1, m = 0, n = 13, p = 8; k <= 8; k += 7, m += 3, n += 3, p -= 7, d -= 64) {
		for (i = 0; i < 8; i++, d += p) {
			for (j = 0; j < 4; j++) {
				t[j] = d[k * j] + d[k * (7 - j)];
				t[7 - j] = d[k * j] - d[k * (7 - j)];
			}
			t[8] = t[0] + t[3];
			t[9] = t[0] - t[3];
			t[10] = t[1] + t[2];
			t[11] = t[1] - t[2];
			d[0] = (t[8] + t[10]) >> m;
			d[4 * k] = (t[8] - t[10]) >> m;
			t[8] = (short) (t[11] + t[9]) * r[10];
			d[2 * k] = t[8] + (short) ((t[9] * r[9]) >> n);
			d[6 * k] = t[8] + (short) ((t[11] * r[11]) >> n);
			t[0] = (short) (t[4] + t[7]) * r[2];
			t[1] = (short) (t[5] + t[6]) * r[0];
			t[2] = t[4] + t[6];
			t[3] = t[5] + t[7];
			t[8] = (short) (t[2] + t[3]) * r[8];
			t[2] = (short) t[2] * r[1] + t[8];
			t[3] = (short) t[3] * r[3] + t[8];
			d[7 * k] = (short) (t[4] * r[4] + t[0] + t[2]) >> n;
			d[5 * k] = (short) (t[5] * r[6] + t[1] + t[3]) >> n;
			d[3 * k] = (short) (t[6] * r[5] + t[1] + t[2]) >> n;
			d[1 * k] = (short) (t[7] * r[7] + t[0] + t[3]) >> n;
		}
	}
}


int
main(void)
{

//====================== Hardware Instrumentation Definitions ======================

    unsigned int anotherControlRegister;
    unsigned int* newRegisterCheck = (unsigned int*)0x80000b00;
    unsigned int current_mode;
    unsigned int* currentModeStatus = (unsigned int*)0x80000b60;
    unsigned int auxiliaryControlRegister;
    unsigned int* addrAuxiliaryControlRegisterBefore = (unsigned int*)0x80000b40;


//====================== Hardware Instrumentation Definitions ======================

    

    asm volatile("MRC p15, 0, %0, c1, c0, 0\t\n": "=r"(anotherControlRegister)); /*assembly para leitura do atual valor de c1 e armazenamento na variavel value;*/
    *newRegisterCheck = anotherControlRegister;

    asm volatile("MRS %0, CPSR" : "=r"(current_mode));
    *currentModeStatus = current_mode;//current_mode;

    asm volatile("MRC p15, 0, %0, c1, c0, 1\t\n": "=r"(auxiliaryControlRegister));
    *addrAuxiliaryControlRegisterBefore = auxiliaryControlRegister;

    init_perfcounters (1, 0); //vamos ver qq rola se comentar a inicializacao dos contadores 
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
	short           a[200] = {0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000,
		0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00,
		0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200,
		0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300,
		0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000,
		0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00,
		0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200,
		0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300,
		0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000,
		0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00,
		0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200,
		0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300,
		0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000,
		0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00,
		0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200,
		0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300,
		0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000,
		0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00,
		0x0800, 0x0200, 0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200,
		0xf800, 0xf300, 0x0400, 0x0000, 0x07ff, 0x0c00, 0x0800, 0x0200, 0xf800, 0xf300, 0x0400
	};
	short           b[200] =
	{0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60,
		0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20,
		0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600,
		0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200,
		0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60,
		0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20,
		0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600,
		0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200,
		0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60,
		0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20,
		0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600,
		0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200,
		0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60,
		0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20,
		0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600,
		0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200,
		0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60,
		0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20,
		0x0c00, 0xf600, 0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600,
		0xf400, 0xf200, 0xf000, 0x0c60, 0x0c40, 0x0c20, 0x0c00, 0xf600, 0xf400, 0xf200, 0xf000
	};
	short           c = 0x3;
	long int        output[200];
	long int        d = 0xAAAA;
	int             e[1] = {0xEEEE};
	/*
	 * Declared as memory variable so it doesn't get optimized out
	 */

	vec_mpy1(a, b, c);
	c = mac(a, b, (long int) c, (long int *) output);
	fir(a, b, output);
	fir_no_red_ld(a, b, output);
	d = latsynth(a, b, N, d);
	iir1(a, b, &output[100], output);
	e[0] = codebook(d, 1, 17, e[0], d, a, c, 1);
	jpegdct(a, b);
	
	//====================== Target Flow ======================
	
	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(numberExecutions)) = numCycles;
	cache_maintenance();
    }



	
	return 0;
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




