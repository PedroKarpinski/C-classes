Definição do problema:
A atividade é composta de um único arquivo (main.c) que contém um programa que faz uma operação “secreta”,
mas apresenta um ou mais vazamentos de memória. Além disso, esse(s) vazamento(s) estão prejudicando a saída
do programa, que está fora do esperado. Não importa o que o programa faz, o importante é que ele possui
vazamentos de memória que precisam ser corrigidos.

O que fazer:
Você precisa rastrear o funcionamento do programa, identificar os vazamentos de memória e corrigi-los. 
O objetivo final é que todos os vazamentos de memória sejam corrigidos e que a saída esperada seja obtida.
Lembre-se da regra geral: para cada chamada de malloc deve haver uma chamada correspondente de free. 
Falhar em chamar free para cada malloc é um vazamento de memória.

Saída esperada:
Uma vez corrigido todos os problemas, a saída do programa deve ser a seguinte:

  Stage 1: Confidential details <br>
  Stage 2: Confidential details (copied)
  Progress: 0 1 2 3 4 5 6 7 8 9 
  
  Stage 3: Confidential details (using data)
  
