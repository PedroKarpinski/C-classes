#include <stdio.h>

void le_vetor(int lista[], int n) {
    int i;
    printf("Digite %d numeros\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }
}

void encontrar_min_max(int lista[], int n) {
    int j;
    int max = 0;
    int min = 10;
    int dif;
    for (j = 0; j < n; j++) {
        if (lista[j] > max)
            max = lista[j];
        if (lista[j] < min)
            min = lista[j];
    }
    dif = max - min;
    printf("A diferenca absoluta eh %d", dif);
}

int main() {
    int a;
    printf("Digite a quantidade de numeros da sua lista\n");
    scanf("%d", &a);
    int lista[a];
    le_vetor(lista, a);
    encontrar_min_max(lista, a);
    return 0;
}