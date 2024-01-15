Questão 1. Escreva um programa em C que leia um número n do usuário e imprima todos os números
pares do intervalo [0, n].

Questão 2. Escreva um programa em C que leia um número n do usuário e imprima todos os números
primos no intervalo [1, n].

Questão 3. No Brasil, medimos a temperatura em Celsius. Já em países de lingua inglesa é muito
comum que a medida de temperatura seja feita em Fahrenheit. A seguinte forma nos permite estabelecer
uma relação entre as duas unidades de medida onde TC é a temperatura em Celsius e TF é a temperatura
em Fahrenheit. Escreva um programa em C que seja capaz de converter um valor de temperatura entre
Celsius e Fahrenheit e vice-versa (pergunte ao usuário qual é unidade de medida da temperatura
de entrada e dê o valor convertido para a outra).

Questão 4. Escreva um programa em C que faça o produto de Hadamard de dois vetores u = (u1, u2, . . . , un)
e v = (v1, v2, . . . , vn), isso é, que compute o vetor(u1v1, u2v2, . . . , unvn). A entrada consiste primeiro
do valor n, onde 1 ≤ n ≤ 100, seguida dos n números reais do vetor u, que é seguida pelos n números
reais do vetor v. Na sua implementação, você deve criar uma função
void produto_hadamard(double u[], double v[], double resultado[])
que será responsável por fazer o produto entre os dois vetores.

Questão 5. Escreva um programa em C que leia uma sequência de n números inteiros e imprima os
seguintes valores: o número mínimo da sequência, o máximo e a média. Na sua implementação, você
deve dividir o seu programa nas seguintes funções
// lê n inteiros fornecidos pelo usuário e armazena -os no vetor entrada
void le_vetor(int entrada[], int n) ;
// retorna o valor mínimo do vetor v que tem n elementos
int minimo(int v[], int n);
// retorna o valor máximo do vetor v que tem n elementos
int maximo(int v[], int n);
// retorna a média dos elementos guardados em um vetor v de n elementos
double media(int v[], int n)
