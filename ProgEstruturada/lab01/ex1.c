#include <stdio.h>

int main() {
    int x, y, z, soma;
    printf("Digite um numero com 4 digitos\n");
    scanf("%d", &x);
    y = x/100;
    z = x%100;
    soma = y+z;
    soma *= soma;
    if (soma == x) {
        printf("Possui a propriedade");
    } else {
        printf("Nao possui a propriedade");
    }
    return 0;
}