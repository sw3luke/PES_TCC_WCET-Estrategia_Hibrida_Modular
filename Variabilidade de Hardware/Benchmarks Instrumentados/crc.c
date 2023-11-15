#include "soc_AM335x.h"
#include "beaglebone.h"

//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 

typedef unsigned char uchar;
#define LOBYTE(x) ((uchar)((x) & 0xFF))
#define HIBYTE(x) ((uchar)((x) >> 8))

unsigned char   lin[256] = "asdffeagewaHAFEFaeDsFEawFdsFaefaeerdjgp";

unsigned short icrc1(unsigned short crc, unsigned char onech);
unsigned short icrc(unsigned short crc, unsigned long len, short jinit, int jrev);

unsigned short
icrc1(unsigned short crc, unsigned char onech)
{
   int             i;
   unsigned short  ans = (crc ^ onech << 8);

   for (i = 0; i < 8; i++) {
      if (ans & 0x8000)
         ans = (ans <<= 1) ^ 4129;
      else
         ans <<= 1;
   }
   return ans;
}

unsigned short
icrc(unsigned short crc, unsigned long len,
     short jinit, int jrev)
{
   unsigned short  icrc1(unsigned short crc, unsigned char onech);
   static unsigned short icrctb[256], init = 0;
   static uchar    rchr[256];
   unsigned short  tmp1, tmp2, j, cword = crc;
   static uchar    it[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

   if (!init) {
      init = 1;
      for (j = 0; j <= 255; j++) {
         icrctb[j] = icrc1(j << 8, (uchar) 0);
         rchr[j] = (uchar) (it[j & 0xF] << 4 | it[j >> 4]);
      }
   }
   if (jinit >= 0) {
      cword = ((uchar) jinit) | (((uchar) jinit) << 8);
   } else if (jrev < 0) {
      cword = rchr[HIBYTE(cword)] | rchr[LOBYTE(cword)] << 8;
   }
   
   for (j = 1; j <= len; j++) {
      if (jrev < 0) {
         tmp1 = rchr[lin[j]] ^ HIBYTE(cword);
      } else {
         tmp1 = lin[j] ^ HIBYTE(cword);
      }
      cword = icrctb[tmp1] ^ LOBYTE(cword) << 8;
   }
   if (jrev >= 0) {
      tmp2 = cword;
   } else {
      tmp2 = rchr[HIBYTE(cword)] | rchr[LOBYTE(cword)] << 8;
   }
   return (tmp2);
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

    int numberExecutions;

   unsigned short  i1, i2;
   unsigned long   n;


    asm volatile("MRC p15, 0, %0, c1, c0, 0\t\n": "=r"(anotherControlRegister)); /*assembly para leitura do atual valor de c1 e armazenamento na variavel value;*/
    *newRegisterCheck = anotherControlRegister;

    asm volatile("MRS %0, CPSR" : "=r"(current_mode));
    *currentModeStatus = current_mode;//current_mode;

    asm volatile("MRC p15, 0, %0, c1, c0, 1\t\n": "=r"(auxiliaryControlRegister));
    *addrAuxiliaryControlRegisterBefore = auxiliaryControlRegister;

    init_perfcounters (1, 0);
    unsigned int numCycles = 0;
    unsigned int overhead = get_cyclecount();

    overhead = get_cyclecount() - overhead;
    unsigned int t = 0;
    unsigned int* addr = (unsigned int*)0x80069FF0;

    init_cache_garbage_array();

    for(numberExecutions = 0; numberExecutions < 50000; numberExecutions++){
	t = get_cyclecount();
	//====================== Target Flow ======================
   	n = 40;
   	lin[n + 1] = 0;
   	i1 = icrc(0, n, (short) 0, 1);
   	lin[n + 1] = HIBYTE(i1);
   	lin[n + 2] = LOBYTE(i1);
   	i2 = icrc(i1, n + 2, (short) 0, 1);
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

	int* garbage_array_addr = (int*)0x80000ba0; //posicao de inicio do array; OBS: Vou deixar esse Addr por enquanto, mas ele esta logo apos o array que armazena o numero de ciclos, entao,
	//por enquanto o addr esta sujeito a mudancas dependendo da quantidade de iteracoes a serem executadas. Para o teste aqui vou deixar esse endereco
	int i;
	for(i = 0; i < 8192; i++){
		*(garbage_array_addr+(i*4)) = 0; //um equivalente de j = j+1 para cada posicao do array    ///*(garbage_array_addr+(i*4)) = 0;
		
		//por que 8192?? Como comentado anteriormente, cada inteiro ocupa 32bits, logo 32 * 8192 = 32KB que e o tamanho de nossa cache e garantira que ela foi substituida
		//PS: podemos colocar um pouco mais de 1024 como gordura, mas em teoria nao e necessario
	}

}


void cache_maintenance(){
	
	//Sintaxe do comando MCR:
	//MCR<c> <coproc>,<opc1>,<Rt>,<CRn>,<CRm>{,<opc2>}
	//Rt -> valor a ser escrito no registrador do coprocessador
	//CRn -> registrador que recebera o valor
	//CRm -> registrador de destino adicional
	//opc2 -> opcode, se nao definido sera 0
	
	
	asm volatile("MCR p15, 0, %0, c7, c5, 0" :: "r"(0));//invalida conteudo da cache de instrucoes, etapa encontrada na documentacao do cortex-a8 no site do arm
	/* https://developer.arm.com/documentation/ddi0344/k/system-control-coprocessor/system-control-coprocessor-registers/c7--cache-operations?lang=en */
	
	
	
	
	/* http://meseec.ce.rit.edu/551-projects/fall2014/2-2.pdf */
	//Com a cache de instrucoes invalidada agora vamos desfavorer a cache de dados, para isso realizaremos uma iteracao acessando e realizando uma operacao em um array grande o suficiente
	
	//Nossa cache L1 possui 32KB, 4-way set associative
	//A politica default e write-back
	
	//Procura do dado ocorre de L1->L2->Memoria Principal
	//No BeagleBone Black a penalidade para um miss e:
		//L1 - 1 ciclo;
		//L2 - 8 ciclos;
	
	
	//Uma vez que a politica da L1 e write-back, temos que uma cache suja e pior do que uma cache limpa, entao para sujar a cache vamos criar um array
	
	//Para facilitar vamos trabalhar com um array de inteiros, logo cada inteiro ocupa 32 bits = 4 bytes;
	
	int* garbage_array_addr = (int*)0x80000ba0;//posicao de inicio do array; OBS: Vou deixar esse Addr por enquanto, mas ele esta logo apos o array que armazena o numero de ciclos, entao,
	//por enquanto o addr esta sujeito a mudancas dependendo da quantidade de iteracoes a serem executadas. Para o teste aqui vou deixar esse endereco
	int i;
	for(i = 0; i < 8192; i++){
		//*(garbage_array_addr+(i*4)) = *(garbage_array_addr+(i*4)) + 1;
		*(garbage_array_addr+(i*4)) = *(garbage_array_addr+(i*4)) + 1; //um equivalente de j = j+1 para cada posicao do array
		
		//por que 8192?? Como comentado anteriormente, cada inteiro ocupa 32bits, logo 32 * 8192 = 32KB que e o tamanho de nossa cache e garantira que ela foi substituida
		//PS: podemos colocar um pouco mais de 1024 como gordura, mas em teoria nao e necessario
		
		//conta:
		// 1KB = 8192 bits = 1024 bytes
		// 1 inteiro tem 4 bytes(32bits), logo para alcancarmos 1KB precisamos de 1024/4 inteiros = 256
		// por fim para alcancarmos 32KB, precisamos de 256*32 = 8192 inteiros
	}
}


//============================== Hardware Measure Routine ==============================






