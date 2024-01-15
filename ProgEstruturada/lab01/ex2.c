#include <stdio.h>

int main() {
    int x, y, z, res;
    printf("Digite 1 para somar\nDigite 2 para subtrair\nDigite 3 para multiplicar\nDigite 4 para dividir\nDigite 5 para sair\n");
    scanf("%d", &x);
    if (x == 5) {
        return 0;
    } else {
        printf("Digite o primeiro numero\n");
        scanf("%d", &y);
        printf("Digite o segundo numero\n");
        scanf("%d", &z);
        if (x == 1) {
            res = y+z;
        } else if (x == 2) {
            res = y-z;
        } else if (x == 3) {
            res = y*z;
        } else if (x == 4) {
            res = y/z;
        }
        printf("O resultado da operacao eh %d\n", res);
    }
    return 0;
}
