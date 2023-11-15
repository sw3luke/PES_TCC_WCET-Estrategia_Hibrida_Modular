#include "soc_AM335x.h"
#include "beaglebone.h"

//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 

int a[11];
void insertsort(){
  int  i,j, temp;
  i = 2;
  while(i <= 10){
      j = i;
      while (a[j] < a[j-1]){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	j--;
      }
      i++;
  }
}
int main(){
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
  	a[0] = 0;   /* assume all data is positive */
  	a[1] = 9; 
  	a[2]=8;
  	a[3]=7; 
  	a[4]=6; 
  	a[5]=5; 
  	a[6]=4; 
  	a[7]=3;
  	a[8]=2; 
  	a[9]=1; 
  	a[10]=0;
  
  	insertsort();
	//====================== Target Flow ======================
	
	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(numberExecutions)) = numCycles;//numCycles; //*(addr+(i*4))= numCycles;
	cache_maintenance();
    }
  
  return 1;
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




