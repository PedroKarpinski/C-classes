#include <stdio.h>

int main() {
    int x;
    printf("Digite um numero\n");
    scanf("%d", &x);
    if (x%15 == 0) {
        printf("%d eh divisivel por 3 e por 5 simultaneamente", x);
    } else {
        printf("%d nao eh divisivel por 3 e 5 simultaneamente", x);
    }
    return 0;
}