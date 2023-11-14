# [PES-TCC-WCET] - Estratégia Híbrida Modular

Membros do Grupo:
- Felipe Delmondes Aires de Brito;
- Gustavo Correia Espírito Santo;
- Ingrid Fortes Vasconcelos Oliveira;
- Lucas Gabriel Barbosa Cunha.

Este repositorio tem como objetivo armazenar, organizar e documentar os artefatos gerados a partir do desenvolvimento do TCC. Ele está dividido em duas grandes etapas, sendo elas:

1. Exploração da variabilidade de software;
2. Exploração da variabilidade de hardware.

Cada qual, possuindo suas próprias documentações, exemplos de uso e tutoriais de instalação.

O projeto foi concebido tendo como objetivo a modularização, motivo esse que resulta na divisão comentada anteriormente. A metodologia detalhada do trabalho pode ser encontrada no artigo [WCET Estratégia Híbrida Modular](https://github.com/sw3luke/PES_TCC_WCET-Estrategia_Hibrida_Modular/blob/master/Artigo_WCET_Estratégia_Híbrida_Modular_RXX.pdf) produzido.

## [Variabilidade de Software](https://github.com/sw3luke/PES_TCC_WCET-Estrategia_Hibrida_Modular/tree/master/Variabilidade%20de%20Software)

A etapa de variabilidade de software abrange 4 macro etapas:
  1. Identificação dos blocos básicos em ALF relativos ao código em C;
  2. Instrumentação e obtenção dos tempos de execução relativos a cada bloco básico;
  3. Execução Abstrata para obtenção do WCEP;
  4. Execução exploratória para obtenção do conjunto de entradas que provoca o WCEP;

## [Variabilidade de Hardware](https://github.com/sw3luke/PES_TCC_WCET-Estrategia_Hibrida_Modular/tree/master/Variabilidade%20de%20Hardware)
  1. Medição de início a fim da execução do código em C utilizando as entradas que provocam o WCEP;

### [Análise Probabilística Baseada em Medições](https://github.com/sw3luke/PES_TCC_WCET-Estrategia_Hibrida_Modular/tree/master/Variabilidade%20de%20Hardware/Análise%20Probabilística%20Baseada%20em%20Medições)
  1. Utilização da Teoria do Valor Extremo para modelagem de curvas de densidade de probabilidade (PDF) a partir dos blocos de medições para o programa avaliado;
  2. Definição do WCEP baseado em um pWCET de 1e-9.


## Sobre nós


| Rede Social   | Link      |    
| ------- | --------------------- | 
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/felipe-delmondes](https://br.linkedin.com/in/felipe-delmondes)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/lucas-cunha-222ba668/](https://www.linkedin.com/in/lucas-cunha-222ba668/)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/ingrid-f-v-oliveira/](https://www.linkedin.com/in/ingrid-f-v-oliveira/)
| ![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)| [br.linkedin.com/in/gustavo-correia-b6044b251/](https://www.linkedin.com/in/gustavo-correia-b6044b251/)

[(Início)](#pes-tcc-wcet---estratégia-híbrida-modular)