//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>

void count_down(int n) {
    if (n > 0) {
        printf("%d\n", n);
        count_down(n-1);
    }
    else if (n == 0)
        printf("ACABOU!");
}

int main() {
    int n;
    printf("Digite um numero n: ");
    scanf("%d", &n);

    printf("Contagem regressiva de %d ate 0:\n", n);
    count_down(n);

    return 0;
}