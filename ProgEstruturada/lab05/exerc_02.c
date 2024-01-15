//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>

void count_up(unsigned int n) {
    if (n > 0) {
        count_up(n-1);
        printf("%u\n", n);
    }
    else if (n == 0)
        printf("%u\n", n);
}

int main() {
    unsigned int n;
    printf("Digite um numero positivo n: ");
    scanf("%u", &n);

    printf("Contagem progressiva de 0 ate %d:\n", n);
    count_up(n);

    return 0;
}