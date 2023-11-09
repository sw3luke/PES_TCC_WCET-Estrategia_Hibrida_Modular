# Instalação e Utilização

Essa seção tem como objetivo abordar a variabilidade de hardware, a partir da execução e armazenamento dos tempos de execução do benchmark em um ambiente bare-metal, utilizando o BeagleBone Black(BBB).
  
## Instalação do UBoot

A fim de carregar programas bare-metal na memória do BBB foi utilizado o UBoot, um bootloader de primeiro e segundo estágio, capaz de realizar a inicialização do hardware, o carregamento do programa e a passagem de controle para o binário. Para isso, é necessário, primeiro, carregar uma versão do UBoot construída visando o BBB, tal versão pode ser obtida realizando o build do próprio source e especificando o hardware alvo ou pegando uma imagem do UBoot pre-built para o hardware alvo.

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

Com as partições criadas e os arquivos do UBoot armazenados na partição BOOT, o usuário já deve ser capaz de acessar o console do UBoot, no BBB, via conexão serial. A fim de estabelecer a conexão serial e testar o funcionamento do bootloader é necessário um emulador de terminal como putty, minicom e etc. No cenário em questão, utilizou-se o minicom.

## Instalação e Configuração do Minicom

Nessa etapa, abordaremos brevemente a instalacao e configuracao do minicom

Para instalar o minicom devemos executar:
~~~
sudo apt-get install minicom
~~~

Em seguida, e necessario realizar a configuracao do minicom, para entrarmos no menu de configuracao devemos executar:
~~~
sudo minicom -s
~~~

Agora basta acessarmos a opcao _Serial port setup_ e configurarmos seguindo a imagem abaixo:

**IMAGEM DO TERMINAL DO MINICOM**

Com o minicom configurado, basta acessarmos seu terminal com o comando
~~~
sudo minicom
~~~

**Imagem do minicom escutando a serial**

**\*OBS**: Caso o cabo USB Serial nao esteja sendo reconhecido pela maquina, o resultado da imagem acima nao sera alcancado.


## Acessando o terminal do UBoot no BBB

Com o UBoot ja no microSD e o minicom corretamente configurado, precisamos conectar o BBB na serial, para isso sera necessario um cabo conversor USB TTL, como visto na imagem abaixo:

**Imagem Cabo Conversor USB TTL**

Agora devemos conectar o cabo no BBB seguindo a seguinte configuracao:

**Imagem da conexao do cabo no BBB**

Com o cabo corretamente conectado, basta energizarmos o BBB com o botao de boot pressionado, fazendo com que o booy seja realizado pelo microSD. Por fim, basta pressionarmos qualquer tecla para que o processo de boot padrao seja cancelado e o terminal do UBoot seja liberado.

**Imagem do terminal do UBoot**

## Configurando Ambiente para Build Bare-Metal

O AM3358x possui uma arquitetura relativamente complexa, o que dificulta a configuracao de todo o hardware. Visando possibilitar a utilizacao bare-metal a Texas Instruments criou o StarterWare, que disponibiliza uma abstracao do hardware do dispositivo, inicializando certos componentes e disponibilizando APIs uteis. Em nosso cenario as APIs disponibilizadas nao serao utilizadas, mas reutilizaremos a estrutura do projeto para realizar o *build* de nossos benchmarks, uma vez que o arquivo .lds e init.S do projeto StarterWare serao uteis para configurarmos alguns aspectos do hardware. 

Nessa secao abordaremos como configurar o ambiente, utilizando como referencia a documentacao disponibilizada pela [octavosystems](https://octavosystems.com/app_notes/bare-metal-on-osd335x-using-u-boot/).

**Obs:** As etapas abaixo foram realizadas em uma maquina com Ubuntu 22.04.2 LTS.

A configuracao do ambiente e dividida em x macro etapas, sendo elas:
1. Instalacao do StarterWare para o AM335x
2. Instalacao do compilador Linaro GCC
3. Build do StarterWare

### Instalacao do StarterWare para o AM335x

Inicialmente e necessario baixarmos o StarterWare para o processador AM335x e o patch para o BeagleBone, que pode, ser obtidos [aqui](http://www.ti.com/tool/starterware-sitara)

Com os arquivos baixados:

1. Abrir terminal;
2. Criar um repositorio para armazenamento dos arquivos;
~~~
mkdir ~/bareMetal
~~~

3. Mover o instalador do StarterWare para o diretorio criado
~~~
mv ~/Downloads/AM335x_Starterware_02_00_01_01_Setup.bin ~/bareMetal
~~~

4. Possibilitar a execucao do instalador
~~~	
cd ~/bareMetal
chmod +x AM335X_StarterWare_02_00_01_01_Setup.bin
~~~

5. Instalar dependencias do StarterWare
~~~
sudo apt-get update
sudo apt-get install zlib1g-dev libncurses5-dev
~~~

6. Executar o instalador
~~~
./AM335X_StarterWare_02_00_01_01_Setup.bin
~~~
7. Durante a instalacao e necessario mudar o caminho de instalacao para ~/bareMetal/AM335X_StarterWare_02_00_01_01 e o tipo de instalacao para *Typical*.
8. Instalar o patch para o BeagleBone Black
~~~
mv ~/Downloads/StarterWare_BBB_support.tar.gz ~/bareMetal/AM335X_StarterWare_02_00_01_01
cd ~/bareMetal/AM335X_StarterWare_02_00_01_01
tar xvfz StarterWare_BBB_support.tar.gz
~~~

### Instalacao do compilador Linaro GCC

Agora vamos instalar o cross-compiler para que possamos compilar nossos benchmarks visando o processador AM335x.

No trabalho foi utilizado a *toolchain* arm-none-eabi, a versao utilizada pode ser obtida [aqui](https://launchpad.net/gcc-arm-embedded/4.7/4.7-2012-q4-major).

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

4. Modificar a variavel "PREFIX" no arquivo aberto no passo 3
~~~
ifndef PREFIX
PREFIX=${LIB_PATH}/bin/arm-none-eabi-
endif
~~~

5. Criar variavel de ambiente para o compilador
~~~
export LIB_PATH=${HOME}/bareMetal/linaro-gcc/gcc-arm-none-eabi-4_7-2012q4
~~~

### Build do StarterWare

Antes de realizarmos o build precisamos, primeiramente, alterar o arquivo init.S, isso se deve ao fato de em nosso processo propormos a desativacao da cache L2.

1. Abrir o arquivo Init.S
~~~
gedit ~/bareMetal/AM335X_StarterWare_02_00_01_01/system_config/armv7a/gcc/init.S
~~~

2. Adicionar o bloco de codigo depois de "Entry:", este bloco sera executado antes do main() presente no source.

O codigo abaixo foi concebido com base nas etapas para [desativacao da cache L2](https://developer.arm.com/documentation/ddi0344/k/level-2-memory-system/enabling-and-disabling-the-l2-cache-controller) disponibilizada na documentacao do ARM Cortex-a8, assim como na documentacao de cada um dos registradores, citados no processo de desativacao, [Control Register](https://developer.arm.com/documentation/ddi0344/k/system-control-coprocessor/system-control-coprocessor-registers/c1--control-register) e [Auxiliary Control Register](https://developer.arm.com/documentation/ddi0344/k/system-control-coprocessor/system-control-coprocessor-registers/c1--auxiliary-control-register)

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

5. Acessar o binario gerado
~~~
cd ~/bareMetal/AM335X_StarterWare_02_00_01_01/binary/armv7a/gcc/am335x/beaglebone/NomeDoExemplo/Release
~~~

### Build dos Benchmarks
