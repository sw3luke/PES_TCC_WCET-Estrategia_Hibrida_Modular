#include "soc_AM335x.h"
#include "beaglebone.h"

// Cosine Transform Coefficients

#define W1 2841                 /* 2048*sqrt(2)*cos(1*pi/16) */
#define W2 2676                 /* 2048*sqrt(2)*cos(2*pi/16) */
#define W3 2408                 /* 2048*sqrt(2)*cos(3*pi/16) */
#define W5 1609                 /* 2048*sqrt(2)*cos(5*pi/16) */
#define W6 1108                 /* 2048*sqrt(2)*cos(6*pi/16) */
#define W7 565                  /* 2048*sqrt(2)*cos(7*pi/16) */

// Other FDCT Parameters
#define CONST_BITS  13
#define PASS1_BITS  2


//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 




int out;


// Image block to be transformed:
short int block[64]=
{ 99 ,104 ,109 ,113 ,115 ,115 , 55 , 55,
  104 ,111 ,113 ,116 ,119 , 56 , 56 , 56,
  110 ,115 ,120 ,119 ,118 , 56 , 56 , 56,
  119 ,121 ,122 ,120 ,120 , 59 , 59 , 59,
  119 ,120 ,121 ,122 ,122 , 55 , 55 , 55,
  121 ,121 ,121 ,121 , 60 , 57 , 57 , 57,
  122 ,122 , 61 , 63 , 62 , 57 , 57 , 57, 
  62 , 62 , 61 , 61 , 63 , 58 , 58 , 58,
};

/* Fast Discrete Cosine Transform */

void fdct(short int *blk, int lx)
{
  int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
  int tmp10, tmp11, tmp12, tmp13;
  int z1, z2, z3, z4, z5;
  int i;
  short int *block;

  int constant;

  /* Pass 1: process rows. */
  /* Note results are scaled up by sqrt(8) compared to a true DCT; */
  /* furthermore, we scale the results by 2**PASS1_BITS. */

  block=blk;

  for (i=0; i<8; i++)
  {
    tmp0 = block[0] + block[7];
    tmp7 = block[0] - block[7];
    tmp1 = block[1] + block[6];
    tmp6 = block[1] - block[6];
    tmp2 = block[2] + block[5];
    tmp5 = block[2] - block[5];
    tmp3 = block[3] + block[4];
    tmp4 = block[3] - block[4];

    /* Even part per LL&M figure 1 --- note that published figure is faulty;
     * rotator "sqrt(2)*c1" should be "sqrt(2)*c6".
     */

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    block[0] = ((tmp10+tmp11) << PASS1_BITS);
    block[4] = ((tmp10-tmp11) << PASS1_BITS);

    constant= 4433;
    z1 = (tmp12 + tmp13) * constant;
    constant= 6270;
    block[2] = (z1 + (tmp13 * constant)) >> (CONST_BITS-PASS1_BITS);
    constant= -15137;
    block[6] = (z1 + (tmp12 * constant)) >> (CONST_BITS-PASS1_BITS);

    /* Odd part per figure 8 --- note paper omits factor of sqrt(2).
     * cK represents cos(K*pi/16).
     * i0..i3 in the paper are tmp4..tmp7 here.
     */

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    constant= 9633;
    z5 = ((z3 + z4) * constant); /* sqrt(2) * c3 */

    constant= 2446;
    tmp4 = (tmp4 * constant); /* sqrt(2) * (-c1+c3+c5-c7) */
    constant= 16819;
    tmp5 = (tmp5 * constant); /* sqrt(2) * ( c1+c3-c5+c7) */
    constant= 25172;
    tmp6 = (tmp6 * constant); /* sqrt(2) * ( c1+c3+c5-c7) */
    constant= 12299;
    tmp7 = (tmp7 * constant); /* sqrt(2) * ( c1+c3-c5-c7) */
    constant= -7373;
    z1 = (z1 * constant); /* sqrt(2) * (c7-c3) */
    constant= -20995;
    z2 = (z2 * constant); /* sqrt(2) * (-c1-c3) */
    constant= -16069;
    z3 = (z3 * constant); /* sqrt(2) * (-c3-c5) */
    constant= -3196;
    z4 = (z4 * constant); /* sqrt(2) * (c5-c3) */

    z3 += z5;
    z4 += z5;

    block[7] = (tmp4 + z1 + z3) >> (CONST_BITS-PASS1_BITS);
    block[5] = (tmp5 + z2 + z4) >> (CONST_BITS-PASS1_BITS);
    block[3] = (tmp6 + z2 + z3) >> (CONST_BITS-PASS1_BITS);
    block[1] = (tmp7 + z1 + z4) >> (CONST_BITS-PASS1_BITS);



    /* advance to next row */
   	block += lx;

  }

  /* Pass 2: process columns. */

  block=blk;

  for (i = 0; i<8; i++)
 	{
    tmp0 = block[0] + block[7*lx];
    tmp7 = block[0] - block[7*lx];
    tmp1 = block[lx] + block[6*lx];
    tmp6 = block[lx]- block[6*lx];
    tmp2 = block[2*lx] + block[5*lx];
    tmp5 = block[2*lx] - block[5*lx];
    tmp3 = block[3*lx] + block[4*lx];
    tmp4 = block[3*lx] - block[4*lx];

    /* Even part per LL&M figure 1 --- note that published figure is faulty;
     * rotator "sqrt(2)*c1" should be "sqrt(2)*c6".
     */

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    block[0] = (tmp10 + tmp11) >> (PASS1_BITS+3);
    block[4*lx] = (tmp10 - tmp11) >> (PASS1_BITS+3);

    constant = 4433;
    z1 = ((tmp12 + tmp13) * constant);
    constant= 6270;
    block[2*lx] = (z1 + (tmp13 * constant)) >> (CONST_BITS+PASS1_BITS+3);
    constant=-15137;
    block[6*lx] = (z1 + (tmp12 * constant)) >> (CONST_BITS+PASS1_BITS+3);

    /* Odd part per figure 8 --- note paper omits factor of sqrt(2).
     * cK represents cos(K*pi/16).
     * i0..i3 in the paper are tmp4..tmp7 here.
     */

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    constant=9633;
    z5 = ((z3 + z4) * constant); /* sqrt(2) * c3 */

    constant=2446;
    tmp4 = (tmp4 * constant); /* sqrt(2) * (-c1+c3+c5-c7) */
    constant=16819;
    tmp5 = (tmp5 * constant); /* sqrt(2) * ( c1+c3-c5+c7) */
    constant=25172;
    tmp6 = (tmp6 * constant); /* sqrt(2) * ( c1+c3+c5-c7) */
    constant=12299;
    tmp7 = (tmp7 * constant); /* sqrt(2) * ( c1+c3-c5-c7) */
    constant=-7373;
    z1 = (z1 * constant); /* sqrt(2) * (c7-c3) */
    constant= -20995;
    z2 = (z2 * constant); /* sqrt(2) * (-c1-c3) */
    constant=-16069;
    z3 = (z3 * constant); /* sqrt(2) * (-c3-c5) */
    constant=-3196;
    z4 = (z4 * constant); /* sqrt(2) * (c5-c3) */

    z3 += z5;
    z4 += z5;

    block[7*lx] = (tmp4 + z1 + z3) >> (CONST_BITS+PASS1_BITS+3);
    block[5*lx] = (tmp5 + z2 + z4) >> (CONST_BITS+PASS1_BITS+3);
    block[3*lx] = (tmp6 + z2 + z3) >> (CONST_BITS+PASS1_BITS+3);
    block[lx] =  (tmp7 + z1 + z4) >> (CONST_BITS+PASS1_BITS+3);

    /* advance to next column */
    block++;
  }
}

int main(void)
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
  	fdct (block, 8);  // 8x8 Blocks, DC precision value = 0, Quantization coefficient (mquant) = 64   
	//====================== Target Flow ======================
	
	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(numberExecutions)) = numCycles;//numCycles; //*(addr+(i*4))= numCycles;
	cache_maintenance();
    }
    

  return block[0];
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



