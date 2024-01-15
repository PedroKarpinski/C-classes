//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>

void collatz(int n) {
    printf("%d ", n);
    if (n == 1)
        return;
    else if (n%2 == 0) {
        n = n/2;
        collatz(n);
    }
    else {
        n = 3*n + 1;
        collatz(n);
    }
}

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    printf("\nSequencia de Collatz para o numero %d:\n", n);
    collatz(n);

    return 0;
}