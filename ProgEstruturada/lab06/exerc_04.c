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

void destruir_lista(Lista* l) {
    Lista atual;
    Lista proximo;
    for (atual = *l; atual->prox != NULL; atual = proximo) {
        proximo = atual->prox;
        free(atual);
    }
}

Lista remover_da_lista(Lista l, int x) {
    if (l == NULL) {
        printf("%d nao esta na lista", x);
        return NULL;
    }
    
    if (l->dado == x) {
        Lista atual = l->prox;
        free(l);
        return atual;
    }

    l->prox = remover_da_lista(l->prox, x);
    return l;
}

void imprimir_lista(Lista l) {
    if (l == NULL) {
        printf("LISTA VAZIA\n");
        return;
    }

    Lista atual;
    for (atual = l; atual != NULL; atual = atual->prox)
        printf("%d ", atual->dado);
    printf("\n");
}

int main() {
    Lista l = criar_lista();
    int elem;

    int num;
    printf("Entrada de inteiros na lista\nDigite -999 quando quiser encerrar a entrada: ");
    do {
        scanf("%d", &num);
        if (num != -999)
            l = adicionar_elemento(l, num);
    } while (num != -999);

    printf("Digite o elemento a ser removido da lista: ");
    scanf("%d", &elem);
    l = remover_da_lista(l, elem);

    printf("Lista apos a remocao da primeira instancia de %d:\n", elem);
    imprimir_lista(l);

    destruir_lista(&l);

    return 0;
}