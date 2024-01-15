//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

typedef struct no* Lista;

struct no {
    int dado;
    Lista prox;
};

Lista criar_lista() {
    return NULL;
}

Lista adicionar_elemento(Lista l, int x) {
    Lista novo;
    novo = malloc(sizeof(struct no));
    novo->dado = x;
    novo->prox = l; 
    return novo;
}

void destruir_lista(Lista l) {
    Lista atual;
    Lista proximo;
    for (atual = l; atual->prox != NULL; atual = proximo) {
        proximo = atual->prox;
        free(atual);
    }
}

Lista busca(Lista l, int x) {
    Lista atual;
    Lista proximo;
    for (atual = l; atual != NULL; atual = proximo) {
        proximo = atual->prox;
        if (atual->dado == x)
            return atual;
    }
    return NULL;
}

int main() {
    Lista l = criar_lista();
    int elem;
    Lista ret;

    int num;
    printf("Entrada de inteirosna lista\nDigite -999 quando quiser encerrar a entrada: ");
    do {
        scanf("%d", &num);
        if (num != 0)
            l = adicionar_elemento(l, num);
    } while (num != -999);

    printf("Digite o elemento a ser buscado na lista: ");
    scanf("%d", &elem);
    ret = busca(l, elem);

    if (ret == NULL)
        printf("%d nao esta na lista", elem);
    else 
        printf("%d esta na lista", ret->dado);

    destruir_lista(l);

    return 0;
}