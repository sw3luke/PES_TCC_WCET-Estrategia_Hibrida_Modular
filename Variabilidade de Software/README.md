# Tutoriais - [PES-TCC-WCET] - Estratégia Híbrida Modular

Nesse repositório estão os tutoriais de instalação e uso do Alf-Backend, do Clang 3.4 e do SWEET, junto de scripts úteis para a execução abstrata.

As instruções de instalação para o ALF-Backend e o SWEET se aplicam a distribuição Ubuntu 22.04.3 do Linux.

# Variabilidade de Software

# Sumário

<details> <summary>Items</summary>

- [Tutorial Instalação Alf-Backend](#tutorial-instalação-alf-backend)

- [Tutorial Instalação Clang 3.4](#tutorial-instalação-clang-34)

- [Tutorial Instalação SWEET](#tutorial-instalação-sweet)

- [Comandos úteis do SWEET](#comandos-úteis-do-sweet-e-alf-backend)

- [Comentários sobre os scripts de Linux](#comentários-sobre-os-scripts-de-linux)

- [Tutorial Instalação SimulAVR](#comentários-sobre-os-scripts-de-linux)

- [Sobre nós](#sobre-nós)


</details>

## Tutorial Instalação Alf-Backend

Obter o repositório oficial do ALF-LLVM.

~~~
    # clone ALF-llvm
    git clone https://github.com/visq/ALF-llvm.git
~~~

Caso haja algum problema com o repositório do ALF-LLVM o código fonte utilizado no trabalho também está disponível nesse repositório na pasta _Programas do Framework_:

Realizar a build do ALF-llvm, a conclusão pode levar alguns minutos.

~~~
	# [ALF-llvm/] Fazer a build do LLVM
	mkdir build
	cd build
	cmake ../
	make
~~~
   	 
Como alternativa também é possível utilizar um script de configuração pronto para fazer a build e configurar.

~~~
	# [ALF-llvm/] Configurar e fazer a build do LLVM
	./configure --enable-assertions && make
~~~

Após a build para usar o ALF-backend é necessário adicionar os binários no PATH do sistema, para isso:

 - Copiar o caminho absoluto da pasta ALF-llvm:

~~~
	# [ALF-llvm/] Obter o caminho absoluto da pasta
	pwd
~~~

 - Abrir o arquivo ~/.bashrc e adicionar no final os seguintes comandos...

~~~
	# export PATH=$PATH:<caminho absoluto para a pasta ALF-llvm/build/bin
~~~

 - Após os passos o uso do seguinte comando deve retornar informações sobre a versão LLVM 3.4

~~~
	# llc --version

LLVM (http://llvm.org/):
  LLVM version 3.4svn
  DEBUG build.
  Built Aug 14 2023 (17:46:17).
  Default target: x86_64-unknown-linux-gnu
  Host CPU: x86-64

~~~



[(Back to top)](#sumário)


## Tutorial Instalação Clang 3.4

Para funcionar com a versão atual 3.4 do ALF-LLVM, o Clang também precisa estar na versão 3.4. Nesse caso, o indicado é buscar os binários pré-compilados para Linux no seguinte link:

[Releases LLVM](https://releases.llvm.org/download.html)

Os binários para o Clang utilizados no trabalho foram obtidos no link abaixo mas também estão disponíveis nesse repositório na pasta _Programas do Framework_:

[Clang 3.4](https://releases.llvm.org/3.4/clang+llvm-3.4-x86_64-unknown-ubuntu12.04.tar.xz)

 - Extrair o arquivo compactado e criar um link simbólico para o executável do Clang dentro da pasta ALF-llvm/build/bin

~~~
	# [ALF-llvm/build/bin] Obter o caminho absoluto da pasta
	ln -s <caminho do Clang/bin/clang> ./clang34
~~~

 - Após os passos o uso do seguinte comando deve retornar informações sobre a versão LLVM 3.4

~~~
	# clang34 --version

clang version 3.4 (tags/RELEASE_34/final)
Target: x86_64-unknown-linux-gnu
Thread model: posix
~~~



[(Back to top)](#sumário)

## Tutorial Instalação SWEET

O código fonte do SWEET se encontra no seguinte link mas também está disponível nesse repositório na pasta _Programas do Framework_:

http://www.mrtc.mdh.se/projects/wcet/sweet/sweet.zip

 - Instalar as dependências do SWEET através do seguinte comando:

~~~
sudo apt-get install cmake libgmp-dev
~~~

 - Extrair o código fonte do SWEET e entrar no diretório sweet/

 - Executar os comandos abaixo para fazer a build do SWEET, a conclusão pode levar alguns minutos.

~~~
	[sweet/]
	mkdir build/
	cd build
	mkdir cmakedir
	cd cmakedir
	cmake ../.. -G "Unix Makefiles"
	make
~~~

 - Copiar o caminho absoluto da pasta do sweet:

~~~
	# [sweet/] Obter o caminho absoluto da pasta
	pwd
~~~

 - Abrir o arquivo ~/.bashrc e adicionar no final os seguintes comandos...

~~~
	# export PATH=$PATH:<caminho absoluto para a pasta do sweet/build/cmakedir/src
~~~

 - Após os passos o uso do seguinte comando deve retornar informações sobre a versão do SWEET

~~~
	# sweet --version

SWEET version 8035 (2019-11-18)
Executing command 'version'.
This executable was built 2023-08-14 from SVN revision 8035 (2019-11-18)
~~~

Ao realizar todos os passos acima, todo o ambiente necessário para converter os arquivos de C para ALF e posteriormente rodar a execução abstrata com o SWEET foi configurado.

## Comandos úteis do SWEET e ALF-Backend

 - **Geração de arquivo CFG**: Para esse comando também é necessário a instalação do graphviz na máquina, essse permite a visualização e conversão de arquivos DOT para imagem.

~~~
sudo apt install graphviz
~~~

Após a instalação a criação do CFG pode ser gerada em PDF para fácil visualização.

~~~
sweet --input-files=arquivo.alf --dot-print file=arquivo g=cfg
dot -Tpdf arquivo.dot > CFG.pdf
~~~

 - **Conversão de C para ALF**: O SWEET realiza as análises no código de nível intermediário chamada ALF. A utilidade do ALF-Backend é proporcionar essa conversão.

~~~
clang34 -Wall -emit-llvm -S -o - arquivo.c | opt -mem2reg -instcombine -instsimplify -instnamer | llvm-dis -o arquivo.ll
llc arquivo.ll -march=alf -o=arquivo.alf
rm arquivo.ll
~~~

Essa função pode ser utilizada pelo script de Linux _c\_to\_alf_, basta executá-lo com o nome do arquivo C como argumento:

~~~
	./c_to_alf arquivo
~~~

 - **Conversão de C para ALF com arquivo de mapeamento**: Além de converter de C para ALF, o ALF-Backend pode fornecer a relação entre as estruturas dos dois formatos com o arquivo de mapeamento _.map_.

~~~
clang34 -g -gcolumn-info -Wall -emit-llvm -S -o - arquivo.c | opt -mem2reg -instcombine -instsimplify -instnamer | llvm-dis -o arquivo.ll
llc arquivo.ll -march=alf -o=arquivo.alf -alf-map-file=arquivo.map
rm arquivo.ll
~~~

Essa função pode ser utilizada pelo script de Linux _c\_to\_alf\_map_, basta executá-lo com o nome do arquivo C como argumento:

~~~
	./c_to_alf_map arquivo
~~~

 - Para a **Execução Abstrata** templates para preenchimento podem ser gerados previamente pelo SWEET.

Para o template de tempos de blocos básicos TDB:

~~~
	sweet -i=arquivo.alf -td o=arquivo.tdb
~~~

Para o template de anotações de entrada ANN:

~~~
	sweet -i=arquivo.alf -at=arquivo.ann
~~~

Por fim, a execução abstrata pode ser executada pelo SWEET com o comando abaixo que recebe como entrada o arquivo .ALF, o arquivo .TDB e o arquivo .ANN, além de parâmetros que indicam por exemplo sobre o uso de estratégias de merge.

~~~
sweet -i=arquivo.alf annot=arquivo.ann -ae pu bbc=arquivo.tdb merge=none bbcpaths -do floats=est
~~~

A saída será os tempos BCET e WCET, junto dos caminhos BCEP e WCEP relacionados.

## Comentários sobre os scripts de Linux

- Antes da utilização do script que será explicado a seguir, é necessário possuir o Python instalado na máquina, normalmente as distribuições recentes de Linux já possuem o Python instalado.

- O script em python utilizado nessa etapa se chama _bb\_identifier\_completo.py_ e é responsável por gerar a partir do _arquivo de mapeamento_ gerado pelo Alf-Backend e do _código em C_ uma equivalência mais simples de ser trabalhada nos formatos txt e csv, o último útil quando utilizado com softwares como Libre Office Calc ou Excel.

- Foi escrito um script chamado **preparacaoAE** que realiza as etapas de conversão do C para ALF, a criação do arquivo de mapeamento, a criação dos templates a serem preenchidos antes de prosseguir com a **Execução Abstrata** e a correspondência de blocos básicos do C para ALF em maiores detalhes com o auxílio de um script em Python. Para utilizá-lo basta chamá-lo junto do caminho do arquivo em C a ser estudado.

~~~
./preparacaoAE arquivo
~~~

## Tutorial Instalação e Utilização SimulAVR

- Para a realização da execução abstrata é necessário, primeiro, medir os blocos básicos do programa, para isso utilizou-se o SimulAVR, um simulador de microcontroladores AVR, essa seção tratará de sua instalação, utilizando a versão das dependências relativas às utilizadas no trabalho.

A primeira etapa abrange a instalação das dependências do SimulAVR, assim como a instalação do próprio SimulAVR.

```
sudo apt-get install binutils-avr=2.26.20160125+Atmel3.6.2-4
```

```
sudo apt-get install gcc-avr=1:5.4.0+Atmel3.6.2-3
```

```
sudo apt-get install avr-libc=1:2.0.0+Atmel3.6.2-3
```

```
sudo apt-get install simulavr=1.0.0+git20160221.e53413b-2build1
```

Com as dependências e a plataforma instalada, podemos passar para a instrumentação do código, para uma explicação mais visual, realizaremos um exemplo utilizando o benchmark bs.c, relativo a implementação do algoritmo binary search.

```
struct DATA {
  int  key;
  int  value;
}  ;

struct DATA data[15] = { {1, 100},
	     {5,200},
	     {6, 300},
	     {7, 700},
	     {8, 900},
	     {9, 250},
	     {10, 400},
	     {11, 600},
	     {12, 800},
	     {13, 1500},
	     {14, 1200},
	     {15, 110},
	     {16, 140},
	     {17, 133},
	     {18, 10} };

int binary_search(int x);

int main(void)
{
	/* a = [0..20]*/ 
	int a = 1;
	binary_search(a);
	return (0);
}

int binary_search(int x)
{
  int fvalue, mid, up, low ;

  low = 0;
  up = 14;
  fvalue = -1 /* all data are positive */ ;
  while (low <= up) {
    mid = (low + up) >> 1;
    if ( data[mid].key == x ) {  /*  found  */
      up = low - 1;
      fvalue = data[mid].value;
    }
    else  /* not found */
      if ( data[mid].key > x ) 	{
	up = mid - 1;
      }
      else   {
             	low = mid + 1;
      }
  }
  return fvalue;
}

```

Para a instrumentação, é necessário consultarmos o arquivo de mapeamento gerado na etapa do ALFBackend, referente ao bs.c, que pode ser encontrado na pasta do benchmark com o nome bs_alf_to_C_identified_full.txt. Haja visto que o objetivo é obtermos o tempo de execução para cada bloco básico, considerado pelo ALF, estaremos analisando a função **int binary_search(int x)**.
A instrumentação será realizada utilizando a biblioteca [AVR-Tick-Counter](https://github.com/malcom/AVR-Tick-Counter), para isso devemos importar o arquivo avr-tick-counter.h em nosso source.

```
#include "avr-tick-counter.h"
.
.
.
int binary_search(int x)
```

Além disso, estaremos recolhendo os tempos de cada bloco básico utilizando através de uma implementação do printf em que a saída será a porta serial, portanto devemos realizar as seguintes declarações em nosso source.

```
#define special_output_port (*((volatile char *)0x20))
int virtual_putchar(char c, FILE *unused)
{
    special_output_port = c;
    return 0;
}
 FILE virtual_port = FDEV_SETUP_STREAM(virtual_putchar, NULL, _FDEV_SETUP_WRITE);
```

Além disso, é crucial mudar o endereço de stdout, dentro da função main:
```
stdout = &virtual_port;
```
Com essas etapas realizadas, estamos prontos para chamar as funções de contagem de ciclos, assim como mostrar os valores obtidos no console serial. Para uma melhor correspondência durante a etapa de instrumentação, devemos consultar dois arquivos, o arquivo bs_alf_to_C_identified_full.txt que representa o mapeamento do código C para ALF, e o arquivo bs.alf que mostra bs.c na representação intermediaria ALF.

Vejamos os primeiros dois blocos listados em bs_alf_to_C_identified_full.txt:

```
Basic Block binary_search bb0
bb0 Line 39   while (low <= up) {
bb0::4:::1 Line 39   while (low <= up) {
bb0::4:::2 Line 39   while (low <= up) {
Basic Block binary_search bb1
bb1 Line 39   while (low <= up) {
```
A representação ALF considera que ambos os blocos bb0 e bb1 representam a mesma linha do código source, portanto foi realizado uma análise no código ALF, onde temos:

```
     /* --------- BASIC BLOCK bb ---------- */
     { label 64 { lref 64 "binary_search::bb" } { dec_unsigned 64 0 } }

     /* STATEMENT binary_search::bb::4
      *   br label %bb1, !dbg !34 */
     { store { addr 64 { fref 64 "%up.0" } { dec_unsigned 64 0 } } with { dec_unsigned 32 14 } }

     { label 64 { lref 64 "binary_search::bb::4:::1" } { dec_unsigned 64 0 } }
     { store { addr 64 { fref 64 "%fvalue.0" } { dec_unsigned 64 0 } } with { dec_signed 32 { minus 1 } } }

     { label 64 { lref 64 "binary_search::bb::4:::2" } { dec_unsigned 64 0 } }
     { store { addr 64 { fref 64 "%low.0" } { dec_unsigned 64 0 } } with { dec_unsigned 32 0 } }

     /* --------- BASIC BLOCK bb1 ---------- */
     { label 64 { lref 64 "binary_search::bb1" } { dec_unsigned 64 0 } }

     /* STATEMENT binary_search::bb1::4
      *   %tmp = icmp sgt i32 %low.0, %up.0, !dbg !34
      *   br i1 %tmp, label %bb25, label %bb2, !dbg !34 */
     { switch
      { s_gt 32 { load 32 { addr 64 { fref 64 "%low.0" } { dec_unsigned 64 0 } } } { load 32 { addr 64 { fref 64 "%up.0" } { dec_unsigned 64 0 } } } }
      { target { dec_signed 1 { minus 1 } }
       { label 64 { lref 64 "binary_search::bb25" } { dec_unsigned 64 0 } }
      }
      { default
       { label 64 { lref 64 "binary_search::bb2" } { dec_unsigned 64 0 } }
      }
     }
```







[(Back to top)](#sumário)

## Sobre nós


| Rede Social   | Link      |    
| ------- | --------------------- | 
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/felipe-delmondes](https://br.linkedin.com/in/felipe-delmondes)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/lucas-cunha-222ba668/](https://www.linkedin.com/in/lucas-cunha-222ba668/)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/ingrid-f-v-oliveira/](https://www.linkedin.com/in/ingrid-f-v-oliveira/)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/gustavo-correia-b6044b251/](https://www.linkedin.com/in/gustavo-correia-b6044b251/)

[(Back to top)](#sumário)
