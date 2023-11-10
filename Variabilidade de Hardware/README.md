# Instalação e Utilização

Essa seção visa abordar a variabilidade de hardware, a partir da execução e armazenamento dos tempos de execução do benchmark em um ambiente bare-metal, utilizando o BeagleBone Black (BBB).
  
## Instalação do UBoot

A fim de carregar programas bare-metal na memória do BBB foi utilizado o UBoot, um bootloader de primeiro e segundo estágio, capaz de realizar a inicialização do hardware, o carregamento do programa e a passagem de controle para o binário. Para isso, é necessário, primeiro, carregar uma versão do UBoot construída visando o BBB, tal versão pode ser obtida realizando o build do próprio source e especificando o hardware alvo ou pegando uma imagem do UBoot pré-built para o hardware alvo.

Por motivos de simplicidade, utilizaremos uma versão já construída, disponibilizada no repositório, na pasta UBoot.

Com os arquivos UBoot.img e MLO baixados, é necessário carregá-los no cartão microSD que será utilizado para o carregamento do Uboot no BBB. Para isso, é de suma importancia que sejam criadas duas partições no microSD:

```
#BOOT --> Partição responsável por armazenar os arquivos do UBoot (MLO e UBoot.img);
  #Label: BOOT
  #Formato: FAT32
  #Tamanho: Necessario para armazenamento dos arquivos - No cenário trabalhado a partição foi criada com 1GB.
  #Flags: boot
```

```
#ROOTFS --> Partição para os demais arquivos.;
  #Label: ROOTFS
  #Formato: EXT4
  #Tamanho: Resto do espaço disponível.
  #Flags: Sem flags.
```
As partições podem ser facilmente criadas e configuradas utilizando a ferramenta GPARTED.

Com as partições criadas e os arquivos do UBoot armazenados na partição BOOT, o usuário já deve ser capaz de acessar o console do UBoot, no BBB, via conexão serial. A fim de estabelecer a conexão serial e testar o funcionamento do bootloader é necessário um emulador de terminal como putty, minicom, etc. No cenário em questão, utilizou-se o minicom.

## Instalação e Configuração do Minicom

Nessa etapa, abordaremos brevemente a instalação e configuração do minicom

Para instalar o minicom devemos executar:
~~~
sudo apt-get install minicom
~~~

Em seguida, é necessario realizar a configuracao do minicom, para entrarmos no menu de configuracao devemos executar:
~~~
sudo minicom -s
~~~

Agora basta acessarmos a opção _Serial port setup_ e configurarmos seguindo a imagem abaixo:

**IMAGEM DO TERMINAL DO MINICOM**

Com o minicom configurado, basta acessarmos seu terminal com o comando
~~~
sudo minicom
~~~

**Imagem do minicom escutando a serial**

**\*OBS**: Caso o cabo USB Serial não esteja sendo reconhecido pela máquina, o resultado da imagem acima não será alcançado.


## Acessando o terminal do UBoot no BBB

Com o UBoot já no microSD e o minicom corretamente configurado, precisamos conectar o BBB na serial, para isso será necessário um cabo conversor USB TTL, como visto na imagem abaixo:

**Imagem Cabo Conversor USB TTL**

Agora devemos conectar o cabo no BBB seguindo a seguinte configuração:

**Imagem da conexao do cabo no BBB**

Com o cabo corretamente conectado, basta energizarmos o BBB com o botão de boot pressionado, fazendo com que o boot seja realizado pelo microSD. Por fim, basta pressionarmos qualquer tecla para que o processo de boot padrão seja cancelado e o terminal do UBoot liberado.

**Imagem do terminal do UBoot**

## Configurando Ambiente para Build Bare-Metal

O AM3358x possui uma arquitetura relativamente complexa, o que dificulta a configuração de todo o hardware. Visando possibilitar a utilização bare-metal a Texas Instruments criou o StarterWare, que disponibiliza uma abstração do hardware do dispositivo, inicializando certos componentes e disponibilizando APIs uteis. Em nosso cenário as APIs disponibilizadas não serão utilizadas, mas reutilizaremos a estrutura do projeto para realizar o *build* de nossos benchmarks, uma vez que o arquivo .lds e init.S do projeto StarterWare serão uteis para configurarmos alguns aspectos do hardware. 

Nessa seção abordaremos como configurar o ambiente, utilizando como referência a documentação disponibilizada pela [octavosystems](https://octavosystems.com/app_notes/bare-metal-on-osd335x-using-u-boot/).

**Obs:** As etapas abaixo foram realizadas em uma máquina com Ubuntu 22.04.2 LTS.

A configuração do ambiente e dividida em x macros etapas, sendo elas:
1. Instalação do StarterWare para o AM335x
2. Instalação do compilador Linaro GCC
3. Build do StarterWare

### Instalação do StarterWare para o AM335x

Inicialmente e necessário baixarmos o StarterWare para o processador AM335x e o patch para o BeagleBone, que pode, ser obtidos [aqui](http://www.ti.com/tool/starterware-sitara)

Com os arquivos baixados:

1. Abrir terminal;
2. Criar um repositório para armazenamento dos arquivos;
~~~
mkdir ~/bareMetal
~~~

3. Mover o instalador do StarterWare para o diretório criado
~~~
mv ~/Downloads/AM335x_Starterware_02_00_01_01_Setup.bin ~/bareMetal
~~~

4. Possibilitar a execução do instalador
~~~	
cd ~/bareMetal
chmod +x AM335X_StarterWare_02_00_01_01_Setup.bin
~~~

5. Instalar dependências do StarterWare
~~~
sudo apt-get update
sudo apt-get install zlib1g-dev libncurses5-dev
~~~

6. Executar o instalador
~~~
./AM335X_StarterWare_02_00_01_01_Setup.bin
~~~
7. Durante a instalação é necessário mudar o caminho de instalação para ~/bareMetal/AM335X_StarterWare_02_00_01_01 e o tipo de instalação para *Typical*.
8. Instalar o patch para o BeagleBone Black
~~~
mv ~/Downloads/StarterWare_BBB_support.tar.gz ~/bareMetal/AM335X_StarterWare_02_00_01_01
cd ~/bareMetal/AM335X_StarterWare_02_00_01_01
tar xvfz StarterWare_BBB_support.tar.gz
~~~

### Instalação do compilador Linaro GCC

Agora vamos instalar o cross-compiler para podermos compilar nossos benchmarks visando o processador AM335x.

No trabalho foi utilizado a *toolchain* arm-none-eabi, a versão utilizada pode ser obtida [aqui](https://launchpad.net/gcc-arm-embedded/4.7/4.7-2012-q4-major).

Com o *cross-compiler* baixado:

1. Criar uma pasta para o compilador e mover o arquivo baixado
~~~
mkdir ~/bareMetal/linaro-gcc
mv ~/Downloads/gcc-arm-none-eabi-4_7-2012q4-20121208-linux.tar.bz2 ~/bareMetal/linaro-gcc
~~~

2. Extrair o compilador
~~~
cd ~/bareMetal/linaro-gcc
tar xvfj gcc-arm-none-eabi-4_7-2012q4-20121208-linux.tar.bz2
~~~

3. Adicionar o caminho do compilador no makefile do StarterWare
~~~
gedit ~/bareMetal/AM335X_StarterWare_02_00_01_01/build/armv7a/gcc/makedefs
~~~

4. Modificar a variável "PREFIX" no arquivo aberto no passo 3
~~~
ifndef PREFIX
PREFIX=${LIB_PATH}/bin/arm-none-eabi-
endif
~~~

5. Criar variável de ambiente para o compilador
~~~
export LIB_PATH=${HOME}/bareMetal/linaro-gcc/gcc-arm-none-eabi-4_7-2012q4
~~~

### Build do StarterWare

Antes de realizarmos a build precisamos, primeiramente, alterar o arquivo init.S, isso se deve ao fato de em nosso processo propormos a desativação da cache L2.

1. Abrir o arquivo Init.S
~~~
gedit ~/bareMetal/AM335X_StarterWare_02_00_01_01/system_config/armv7a/gcc/init.S
~~~

2. Adicionar o bloco de código depois de "Entry:", este bloco será executado antes do main() presente no source.

O código abaixo foi concebido com base nas etapas para [desativação da cache L2](https://developer.arm.com/documentation/ddi0344/k/level-2-memory-system/enabling-and-disabling-the-l2-cache-controller) disponibilizada na documentação do ARM Cortex-a8, assim como na documentação de cada um dos registradores, citados no processo de desativação, [Control Register](https://developer.arm.com/documentation/ddi0344/k/system-control-coprocessor/system-control-coprocessor-registers/c1--control-register) e [Auxiliary Control Register](https://developer.arm.com/documentation/ddi0344/k/system-control-coprocessor/system-control-coprocessor-registers/c1--auxiliary-control-register)

~~~
	SUB r0, r0, r0
	MCR   p15, 0, r0, c1, c0, 0  @ Disable MMU, Data Cache, Instruction Cache and Error Handlings
	
	@===========================================
	SUB r4, r4, r4
	MRC p15, 0, r4, c1, c0, 1
  	BIC r4, r4, #(1 << 1)     @ Disable L2EN (bit 1)
  	MCR p15, 0, r4, c1, c0, 1
  	@===========================================
    	
	@ =========================================
	MRC p15, 0, r0, c1, c0, 0
	
	ORR r0, r0, #(1 << 0)    @ Enable MMU
	ORR r0, r0, #(1 << 2)     @ Enable C bit (bit 2)
	ORR r0, r0, #(1 << 12)     @ Enable I bit (bit 12)
	
	MCR   p15, 0, r0, c1, c0, 0
	@ =========================================
~~~

3. Salve e feche o arquivo
4. Realizar o Build dos exemplos
~~~
cd ~/bareMetal/AM335X_StarterWare_02_00_01_01/build/armv7a/gcc/am335x/beaglebone
make
~~~

5. Acessar o binário gerado
~~~
cd ~/bareMetal/AM335X_StarterWare_02_00_01_01/binary/armv7a/gcc/am335x/beaglebone/NomeDoExemplo/Release
~~~

### Build dos Benchmarks

Até agora vimos como configurar o ambiente e buildar os exemplos básicos já presentes no projeto StarterWare. Nesta seção, trataremos de como realizar o build de nossos próprios códigos, utilizando a estrutura já disponibilizada pelo StarterWare.

1. Acessar a pasta de exemplos, onde o código, alvo do build, deverá ser colocado
~~~
cd ~/bareMetal/AM335X_StarterWare_02_00_01_01/examples/
~~~

2. Criar uma pasta para o código alvo
~~~
mkdir <NomeDoExemplo>
~~~
3. Colocar o arquivo <NomeDoExemplo>.c dentro da pasta criada
4. Criar o arquivo link e o arquivo makefile
~~~
cd ~bareMetal/AM335X_StarterWare_02_00_01_01/build/armv7a/gcc/am335x/beaglebone
mkdir <NomeDoExemplo>
cd <NomeDoExemplo>
~~~

5. Com a pasta criada, devemos criar 2 arquivos dentro dela, o arquivo de link do source e o arquivo de makefile. Aqui reutilizaremos o .lds dos outros exemplos, disponibilizado pelo projeto StarterWare para o AM335x, que será o mesmo para todos os códigos.

\<NomeDoExemplo\>.lds :

~~~
/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
*/
/* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/* ld script for StarterWare AM335x */

/*
** The stack is kept at end of the image, and its size is 128 MB.
** The heap section is placed above the stack to support I/O
** operations using semihosting. The size of the section is 2KB.
*/

MEMORY
{
    DDR0 :   o = 0x80000000,  l = 0x10000000  /* 256MB external DDR Bank 0 */
}

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{

        .startcode :
        {
            . = ALIGN(4);
            *init.o      (.text)
        } >DDR0

        .text :
        {
            . = ALIGN(4);
            *(.text*)
            *(.rodata*)
        } >DDR0

        .data :
        {
            . = ALIGN(4);
            *(.data*)
        } >DDR0

        .bss :
        {
            . = ALIGN(4);
            _bss_start = .;
            *(.bss*)
            *(COMMON)
            _bss_end = .;
        } >DDR0

        .heap :
        {
            . = ALIGN(4);
            __end__ = .;
            end = __end__;
            __HeapBase = __end__;
            *(.heap*)
            . = . + 0x800;
            __HeapLimit = .;
        } >DDR0

        .stack :
        {
            . = ALIGN(4);
            __StackLimit = . ;
            *(.stack*)
            . = . + 0x7FFFFF8;
            __StackTop = .;
        } >DDR0
        _stack = __StackTop;

}

~~~

Criar e alterar o arquivo makefile substituindo \<omeDoExemplo\> pelo escolhido.

makefile :
~~~
#
# Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
#
# 
#  Redistribution and use in source and binary forms, with or without 
#  modification, are permitted provided that the following conditions 
#  are met:
#
#    Redistributions of source code must retain the above copyright 
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the 
#    documentation and/or other materials provided with the   
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#
#******************************************************************************

#
# Locating the root directory
#
ROOT=../../../../../../

#
# Device and EVM definitions
#
DEVICE=am335x
EVM=beaglebone

#
# Include the makefile definitions. This contains compiler, linker and
# archiver definitions and options
#
include ${ROOT}/build/armv7a/gcc/makedefs

#
# Target Directories that need to be built
#
DIRS=${DRIVERS_BLD} ${PLATFORM_BLD} ${SYSCONFIG_BLD} ${UTILITY_BLD}

#
# The application directory and name
#
APPDIR=<NomeDoExemplo>
APPNAME=<NomeDoExemplo>

#
# Where the application will be loaded to. This is required to generate
# image with Header (Load Address and Size)
#
IMG_LOAD_ADDR = 0x80000000

#
# Application Location
#
APP=${ROOT}examples/${EVM}/$(APPDIR)/
APP_BIN=${ROOT}/binary/${TARGET}/${COMPILER}/${DEVICE}/${EVM}/$(APPDIR)

#
# Application source files
#
APP_SRC=$(APP)/*.c

#
# Required library files
#
APP_LIB=-ldrivers  \
	-lutils    \
	-lplatform \
	-lsystem_config

#
# Rules for building the application and library
#
all: debug release

debug:
	make TARGET_MODE=debug lib
	make TARGET_MODE=Debug bin

release:
	make TARGET_MODE=release lib
	make TARGET_MODE=Release bin

lib:
	@for i in ${DIRS};				\
	do						\
		if [ -f $${i}/makefile ] ;		    \
		then					  \
			make $(TARGET_MODE) -C $${i} || exit $$?; \
		fi;					   \
	done;


bin:
	$(CC)  $(CFLAGS) $(APP_SRC)
	@mkdir -p $(TARGET_MODE)/
	@mv *.o* $(TARGET_MODE)/
	$(LD) ${LDFLAGS} ${LPATH} -o $(TARGET_MODE)/$(APPNAME).out \
          -Map $(TARGET_MODE)/$(APPNAME).map $(TARGET_MODE)/*.o* \
          $(APP_LIB) -lc -lgcc $(APP_LIB) $(RUNTIMELIB) -T $(APPNAME).lds
	@mkdir -p $(APP_BIN)/$(TARGET_MODE)
	@cp $(TARGET_MODE)/$(APPNAME).out $(APP_BIN)/$(TARGET_MODE)/$(APPNAME).out
	$(BIN) $(BINFLAGS) $(APP_BIN)/$(TARGET_MODE)/$(APPNAME).out \
               $(APP_BIN)/$(TARGET_MODE)/$(APPNAME).bin 
	cd $(ROOT)/tools/ti_image/; gcc tiimage.c -o a.out; cd - 
	       $(ROOT)/tools/ti_image/a.out $(IMG_LOAD_ADDR) NONE \
               $(APP_BIN)/$(TARGET_MODE)/$(APPNAME).bin \
               $(APP_BIN)/$(TARGET_MODE)/$(APPNAME)_ti.bin; rm -rf $(ROOT)/tools/ti_image/a.out;


#
# Rules for cleaning
#
clean:
	@rm -rf Debug Release $(APP_BIN)/Debug $(APP_BIN)/Release

clean+: clean
	@make TARGET_MODE=clean lib


~~~

6. Adicionar novo diretório criado no arquivo makefile para que o build seja realizado.

~~~
gedit ~bareMetal/AM335X_StarterWare_02_00_01_01/build/armv7a/gcc/am335x/beaglebone/makefile
~~~

7. Com o makefile aberto adicionar o novo diretorio na seção DIRS e salvar
~~~
DIRS=platform \
	.
	.
	.
    <NomeDoExemplo> \
	.
	.
	.
     binary_search \
~~~

8. Agora basta realizar o build novamente do projeto e, caso não haja erros de sintaxe, o arquivo .bin será gerado na pasta de binarios vista anteriormente.

~~~
cd ~/bareMetal/AM335X_StarterWare_02_00_01_01/build/armv7a/gcc/am335x/beaglebone
make clean
make
~~~

## Instrumentação em hardware

Agora que temos o ambiente configurado e sabemos como gerar o binário para um código customizado, para a execução no BBB, podemos instrumentar o código para a medição ponta a ponta no hardware. Essa seção tratará da instrumentação colocada no código fonte.

A fase de instrumentação define 4 funções principais as quais os cabeçalhos podem ser vistos abaixo. A seguir trataremos de cada uma separadamente.

~~~
//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 
~~~






~~~
//====================== Hardware Instrumentation Definitions ======================

    unsigned int anotherControlRegister;
    unsigned int* newRegisterCheck = (unsigned int*)0x8009af70;
    unsigned int current_mode;
    unsigned int* currentModeStatus = (unsigned int*)0x8009af80;
    unsigned int auxiliaryControlRegister;
    unsigned int* addrAuxiliaryControlRegisterBefore = (unsigned int*)0x8009af90;


//====================== Hardware Instrumentation Definitions ======================
~~~

~~~

~~~





## Executando Binário no BBB via microSD

Agora que temos nosso binário gerado, podemos passar para a fase de execução



~~~
load mmc 0:2 0x80000000 <NomeDoExemplo>.bin
~~~
