Definição do problema:
A biblioteca string_lib define um tipo de dado String que contém um array de caracteres e um inteiro
positivo representando o tamanho da string, ambos membros de uma estrutura. A memória para nossas 
strings será alocada dinamicamente. A estrutura String é definida como segue:

  typedef struct {
    char* data; // Ponteiro para o conteudo da string
    int length; // Tamanho da string (excluindo o terminador nulo)
  }   String;

Diferentemente das strings nativas de C, a nossa estrutura String armazena o próprio tamanho, o que 
permite saber quando ela termina, sem depender do terminador nulo (\0). Ou seja, a String “abc” 
terá tamanho 3, e não 4. As operações possíveis nessa estrutura encontram-se no arquivo string_lib.h:

  #ifndef STRING_LIB_H
  #define STRING_LIB_H

  String* string_create(char* content, int len);
  void string_destroy(String* str);
  void string_print(String str);
  String* string_reverse(String str);
  void string_append(String *str1, String str2);

  #endif

Algumas operações já estão implementadas no arquivo string_lib.c, a saber: string_create, 
string_destroy, string_print.

O que fazer:
O seu trabalho consiste em implementar as funções restantes, que são as seguintes:

String* string_reverse(String str): Retorna uma nova string com os caracteres da string original 
em ordem reversa.

void string_append(String *str1, String str2): Adiciona o conteúdo da string str2 ao final da 
string str1. Por exemplo, se str1 contém “abc” e str2 contém “def”, após a chamada 
string_append(&str1, str2), str1 conterá “abcdef”. Note que a função não retorna uma nova 
string, mas modifica a string passada como parâmetro.

Teste as funções implementadas no arquivo main.c.