//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>

int fat (int n) {
    if (n == 0) /* caso base */
        return 1;
    else /* caso geral */
        return n * fat(n-1); /* instância menor */
}

int n_escolhe_k(int n, int k) {
    int i = n-1;

    if (i+1 == k) /* caso base */
        return 1;
    else /* caso geral */
        return fat(i)/(fat(k-1)*fat(i-k+1)) + fat(i)/(fat(k)*fat(i-k)); /* instância menor */
}

int main() {
    int n, k;
    int resultado;
    printf("Digite os valores de n e k: ");
    scanf("%d %d", &n, &k);

    resultado = n_escolhe_k(n, k);
    printf("%d escolhe %d = %d", n, k, resultado);

    return 0;
}