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

void insert(Lista *l, int x) {
    Lista novo;
    novo = malloc(sizeof(struct no));
    novo->dado = x;
    novo->prox = *l;
    *l = novo;
}

void imprime_lista(Lista l) {
    if (l == NULL) {
        printf("LISTA VAZIA\n");
        return;
    }

    Lista atual;
    for (atual = l; atual != NULL; atual = atual->prox)
        printf("%d ", atual->dado);
    printf("\n");
}

void destruir_lista(Lista* l) {
    Lista atual;
    Lista proximo;
    for (atual = *l; atual->prox != NULL; atual = proximo) {
        proximo = atual->prox;
        free(atual);
    }
}

void concatena_listas(Lista *l1, Lista *l2) {
    Lista atual = *l1;
    Lista proximo = NULL;
    
    for (atual = *l1; atual != NULL; atual = proximo) {
        proximo = atual->prox;    
        if (proximo == NULL) {
            atual->prox = *l2; 
            break;
        }
    }
}

int main() {
    Lista l1 = criar_lista();
    Lista l2 = criar_lista();

    int num;
    printf("Entrada de inteiros na lista 1\nDigite -999 quando quiser encerrar a entrada: ");
    do {
        scanf("%d", &num);
        if (num != -999)
            insert(&l1, num);
    } while (num != -999);

    printf("Entrada de inteiros na lista 2\nDigite -999 quando quiser encerrar a entrada: ");
    do {
        scanf("%d", &num);
        if (num != -999)
            insert(&l2, num);
    } while (num != -999);

    printf("Lista 1 antes de ser concatenada com Lista 2:\n");
    imprime_lista(l1);

    concatena_listas(&l1, &l2);

    printf("Lista 1 apos a concatenacao com Lista 2:\n");
    imprime_lista(l1);
    
    destruir_lista(&l1);
    //l2 já foi destruída ao destruir l1 após a concatenação
    
    return 0;
}