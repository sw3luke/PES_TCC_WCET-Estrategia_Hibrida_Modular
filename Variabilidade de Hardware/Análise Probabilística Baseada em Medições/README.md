# Tutoriais - [PES-TCC-WCET] - Análise Probabilística Baseada em Medições

Nesse repositório estão os tutoriais de de uso dos scripts relacionados ao MBPTA

A metodologia detalhada do trabalho pode ser encontrada no artigo [WCET Estratégia Híbrida Modular](https://github.com/sw3luke/PES_TCC_WCET-Estrategia_Hibrida_Modular/blob/master/Artigo_WCET_Estratégia_Híbrida_Modular_RXX.pdf) produzido.

# Análise Probabilística Baseada em Medições

# Sumário

<details> <summary>Items</summary>

- [Análise Probabilística Baseada em Medições e o TVE](#análise-probabilística-baseada-em-medições-e-o-tve)

- [Leituras complementares](#leituras-complementares)

- [Sobre nós](#sobre-nós)


</details>

## Análise Probabilística Baseada em Medições e o TVE

A análise probabilística consiste na utilização da Teoria do Valor Extremo, ramo da estatística empregado na estimação da probabilidade de eventos e fenômenos incomuns/extremos. A TVE baseia-se na modelagem de curvas de densidade de probabilidade (PDF) geradas a partir de dados de medição de tempos de execução do programa avaliado. A aplicação da teoria baseia-se na existência de requisitos mínimos:

 - Dados podem ser representados por variáveis aleatórias;
 - Dados são independentes e identicamente distribuídos (I.I.D.).

A verificação da hipótese de dados I.I.D. é feita a partir de testes estatísticos, como K-Sample Anderson-Darling, Kolmogorov Smirnov, Wald Wolfowitz Runs e Ljung-Box. Os 4 testes foram implementados no script Python evt\_validation\_test. O código realiza os 4 testes acima, retornando o valor de p-value de cada teste. Considera-se que os dados passaram no teste se p-value >= 0.05.

A verificação da hipótese de dados I.I.D. é feita a partir de testes estatísticos, como K-Sample Anderson-Darling, Kolmogorov Smirnov, Wald Wolfowitz Runs e Ljung-Box. Os 4 testes foram implementados no script Python evt_validation_test. O código realiza os 4 testes acima, retornando o valor de p-value de cada teste. Considera-se que os dados passaram no teste se p-value >= 0.05.

~~~
    python evt_validation_test.py ‘arquivo.txt’ 2
~~~

Onde devem ser fornecidos como entradas o conjunto de medidas de tempo de execução e o número de amostras a qual o conjunto de dados deve ser dividido.
Uma vez verificado a hipótese de I.I.D., a TVE pode ser aplicada para obtenção do valor de WCET dos dados, a partir do script pWCET. Este script realiza o ajuste da curva PDF criada pelos dados fornecidos por um modelo GEV (Generalized Extreme Value), a partir de dois métodos (Levenberg-Marquardt e Maximum Likelihood Estimation), retornando um valor de WCET para uma dada probabilidade de excedência. Além disso, o script utiliza o método de seleção de dados Máximo de Blocos.

A execução do script é feita pelo comando:


~~~
	python pWCET.py ‘arquivo.txt’ 50 1e-9
~~~
   	 
Onde os argumentos de entrada são: arquivo txt a ser medido, tamanho de bloco, valor de probabilidade de excedência.
Ao executar o comando, a primeira figura aberta é a do histograma de densidade de probabilidade de ocorrência dos tempos de execução, bem como a sua curva PDF. Nesse ponto, é importante anotar em qual valor de tempo de execução se encontra o pico máximo da curva. Este valor será utilizando no ajuste da curva.
Fechando a curva, serão solicitados valores iniciais para os parâmetros ξ, μ, e σ. Um exemplo de valores iniciais é apresentado a seguir:

 - ξ = 0
 - μ = (Valor anotado anteriormente)
 - σ = 20

Em seguida, será exibido o ajuste realizado. Ao fechar a figura do ajuste, é possível continuar o fit da curva inserindo novos valores, basta responder ‘y’, para a pergunta:

~~~
	Continue with fitting? Yes [y] or No [n]?
	y
~~~

 Se o ajuste foi satisfatório, responda ‘n’.
Em seguida, será exibido a seguinte mensagem:


~~~
	Do you want to perform a Gumbel fit? Yes [y] or No [n]?
~~~

Caso o parâmetro ξ obtido seja < 0, é recomendado que seja feito o ajuste pela curva Gumbel. Caso contrário, apenas responda ‘n’. Assim a análise retornará os valores de cada parâmetro ajustado pelos dois métodos, bem como o valor de WCET dado a probabilidade de excedência fornecida.
O comando –help fornece a documentação dos dois códigos para mais informações.


[(Back to top)](#sumário)


## Leituras complementares



[(Back to top)](#sumário)



| Rede Social   | Link      |    
| ------- | --------------------- | 
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/felipe-delmondes](https://br.linkedin.com/in/felipe-delmondes)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/lucas-cunha-222ba668/](https://www.linkedin.com/in/lucas-cunha-222ba668/)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/ingrid-f-v-oliveira/](https://www.linkedin.com/in/ingrid-f-v-oliveira/)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/gustavo-correia-b6044b251/](https://www.linkedin.com/in/gustavo-correia-b6044b251/)

[(Back to top)](#sumário)
