#include <stdio.h>

int main() {
    int x;
    printf("Digite um numero inteiro\n");
    scanf("%d", &x);
    if (x<10) {
        printf("Eh capicua");
    } else if (x>=10) {
        if (x<100) {
            if (x/10 == x%10) {
                printf("Eh capicua");
            } else {
                printf("Nao eh capicua");
            }
        } else if (x>=100) {
            if (x<1000) {
                if (x/100 == x%100) {
                    printf("Eh capicua");
                } else {
                    printf("Nao eh capicua");
                }
            }
        }
    }
    return 0;
}