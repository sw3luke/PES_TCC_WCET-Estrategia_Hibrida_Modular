#include "soc_AM335x.h"
#include "beaglebone.h"


//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 


int swi120(int c);
int swi50(int c);
int swi10(int c);

int swi120(int c)
{
	int i;
	for (i=0; i<120; i++) {
		switch (i) {
			case 0: c++; break;
			case 1: c++; break;
			case 2: c++; break;
			case 3: c++; break;
			case 4: c++; break;
			case 5: c++; break;
			case 6: c++; break;
			case 7: c++; break;
			case 8: c++; break;
			case 9: c++; break;
			case 10: c++; break;
			case 11: c++; break;
			case 12: c++; break;
			case 13: c++; break;
			case 14: c++; break;
			case 15: c++; break;
			case 16: c++; break;
			case 17: c++; break;
			case 18: c++; break;
			case 19: c++; break;
			case 20: c++; break;
			case 21: c++; break;
			case 22: c++; break;
			case 23: c++; break;
			case 24: c++; break;
			case 25: c++; break;
			case 26: c++; break;
			case 27: c++; break;
			case 28: c++; break;
			case 29: c++; break;
			case 30: c++; break;
			case 31: c++; break;
			case 32: c++; break;
			case 33: c++; break;
			case 34: c++; break;
			case 35: c++; break;
			case 36: c++; break;
			case 37: c++; break;
			case 38: c++; break;
			case 39: c++; break;
			case 40: c++; break;
			case 41: c++; break;
			case 42: c++; break;
			case 43: c++; break;
			case 44: c++; break;
			case 45: c++; break;
			case 46: c++; break;
			case 47: c++; break;
			case 48: c++; break;
			case 49: c++; break;
			case 50: c++; break;
			case 51: c++; break;
			case 52: c++; break;
			case 53: c++; break;
			case 54: c++; break;
			case 55: c++; break;
			case 56: c++; break;
			case 57: c++; break;
			case 58: c++; break;
			case 59: c++; break;
			case 60: c++; break;
			case 61: c++; break;
			case 62: c++; break;
			case 63: c++; break;
			case 64: c++; break;
			case 65: c++; break;
			case 66: c++; break;
			case 67: c++; break;
			case 68: c++; break;
			case 69: c++; break;
			case 70: c++; break;
			case 71: c++; break;
			case 72: c++; break;
			case 73: c++; break;
			case 74: c++; break;
			case 75: c++; break;
			case 76: c++; break;
			case 77: c++; break;
			case 78: c++; break;
			case 79: c++; break;
			case 80: c++; break;
			case 81: c++; break;
			case 82: c++; break;
			case 83: c++; break;
			case 84: c++; break;
			case 85: c++; break;
			case 86: c++; break;
			case 87: c++; break;
			case 88: c++; break;
			case 89: c++; break;
			case 90: c++; break;
			case 91: c++; break;
			case 92: c++; break;
			case 93: c++; break;
			case 94: c++; break;
			case 95: c++; break;
			case 96: c++; break;
			case 97: c++; break;
			case 98: c++; break;
			case 99: c++; break;
			case 100: c++; break;
			case 101: c++; break;
			case 102: c++; break;
			case 103: c++; break;
			case 104: c++; break;
			case 105: c++; break;
			case 106: c++; break;
			case 107: c++; break;
			case 108: c++; break;
			case 109: c++; break;
			case 110: c++; break;
			case 111: c++; break;
			case 112: c++; break;
			case 113: c++; break;
			case 114: c++; break;
			case 115: c++; break;
			case 116: c++; break;
			case 117: c++; break;
			case 118: c++; break;
			case 119: c++; break;
			default: c--; break;
		}
	}
	return c;
}


int swi50(int c)
{
	int i;
	for (i=0; i<50; i++) {
		switch (i) {
			case 0: c++; break;
			case 1: c++; break;
			case 2: c++; break;
			case 3: c++; break;
			case 4: c++; break;
			case 5: c++; break;
			case 6: c++; break;
			case 7: c++; break;
			case 8: c++; break;
			case 9: c++; break;
			case 10: c++; break;
			case 11: c++; break;
			case 12: c++; break;
			case 13: c++; break;
			case 14: c++; break;
			case 15: c++; break;
			case 16: c++; break;
			case 17: c++; break;
			case 18: c++; break;
			case 19: c++; break;
			case 20: c++; break;
			case 21: c++; break;
			case 22: c++; break;
			case 23: c++; break;
			case 24: c++; break;
			case 25: c++; break;
			case 26: c++; break;
			case 27: c++; break;
			case 28: c++; break;
			case 29: c++; break;
			case 30: c++; break;
			case 31: c++; break;
			case 32: c++; break;
			case 33: c++; break;
			case 34: c++; break;
			case 35: c++; break;
			case 36: c++; break;
			case 37: c++; break;
			case 38: c++; break;
			case 39: c++; break;
			case 40: c++; break;
			case 41: c++; break;
			case 42: c++; break;
			case 43: c++; break;
			case 44: c++; break;
			case 45: c++; break;
			case 46: c++; break;
			case 47: c++; break;
			case 48: c++; break;
			case 49: c++; break;
			case 50: c++; break;
			case 51: c++; break;
			case 52: c++; break;
			case 53: c++; break;
			case 54: c++; break;
			case 55: c++; break;
			case 56: c++; break;
			case 57: c++; break;
			case 58: c++; break;
			case 59: c++; break;
			default: c--; break;
		}
	}
	return c;
}


int swi10(int c)
{
	int i;
	for (i=0; i<10; i++) {
		switch (i) {
			case 0: c++; break;
			case 1: c++; break;
			case 2: c++; break;
			case 3: c++; break;
			case 4: c++; break;
			case 5: c++; break;
			case 6: c++; break;
			case 7: c++; break;
			case 8: c++; break;
			case 9: c++; break;
			default: c--; break;
		}
	}
	return c;
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
	int cnt=0;

	cnt=swi10(cnt);
	cnt=swi50(cnt);
	cnt=swi120(cnt);
	//====================== Target Flow ======================
	
	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(numberExecutions)) = numCycles;
	cache_maintenance();
    }
    
    
    
    
    
    
    

	/* cnt=[0...50] */


	//return cnt; /*devido a declaracao estar dentro do for este return nao ira funcionar*/

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




