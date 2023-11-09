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


##Acessando o terminal do UBoot no BBB

Com o UBoot ja no microSD e o minicom corretamente configurado, precisamos conectar o BBB na serial, para isso sera necessario um cabo conversor USB TTL, como visto na imagem abaixo:

**Imagem Cabo Conversor USB TTL**

Agora devemos conectar o cabo no BBB seguindo a seguinte configuracao:

**Imagem da conexao do cabo no BBB**

Com o cabo corretamente conectado, basta energizarmos o BBB com o botao de boot pressionado, fazendo com que o booy seja realizado pelo microSD. Por fim, basta pressionarmos qualquer tecla para que o processo de boot padrao seja cancelado e o terminal do UBoot seja liberado.

**Imagem do terminal do UBoot**


  1. Kit de desenvolvimento BeagleBone Black;
  2. UBoot;
  3. StarterWare.
