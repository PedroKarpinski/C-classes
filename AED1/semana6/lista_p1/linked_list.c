#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    int size;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

void list_destroy(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void list_insertAfter(LinkedList* list, int pos, Element element) {
    if (list->head == NULL || pos < 0) {
        list_insertFirst(list, element);
    } else {
        Node* cur = list->head;
        int i = 0;

        while (i < pos && cur->next != NULL) {
            cur = cur->next;
            i++;
        }

        Node* newNode = malloc(sizeof(Node));

        newNode->element = element;
        newNode->next = cur->next;
        cur->next = newNode;
        list->size++;
    }
}

void list_print(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        element_print(cur->element);
        cur = cur->next;
        if (cur != NULL) {
            printf(" -> ");
        }        
    }
    printf("\n");
}

bool list_removeFirst(LinkedList* list) {
    if (list->head == NULL)
        return false;

    Node* trash = list->head;

    list->head = list->head->next;
    free(trash);
    list->size--;

    return true;
}

bool list_removeAt(LinkedList* list, int pos) {
    if (pos < 0 || pos >= list->size)
        return false;

    if (pos == 0)
        return list_removeFirst(list);
    else {
        Node* prev = list->head;
        int i = 0;

        while (i < pos-1) {
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;

        prev->next = prev->next->next;
        free(trash);
        list->size--;
    }

    return true;
}

bool list_isEmpty(LinkedList* list) {
    return list->head == NULL;
}

int list_size(LinkedList* list) {
    return list->size;
}

Element list_element(LinkedList* list, int pos) {
    if (pos < 0 || pos >= list->size)
        return ELEMENT_NULL;

    int cont = 0;
    Node* cur = list->head;

    while (cur != NULL) {
        if (cont == pos)
            return cur->element;
        
        cont++;
        cur = cur->next;
    }

    return ELEMENT_NULL;
}

LinkedList* list_copy(LinkedList* list) {
    LinkedList* list_ret = list_create();
    list_ret->size = list->size;

    int cont = 0;
    Node* cur = list->head;
    while (cur != NULL) {
        list_insertAfter(list_ret, cont, cur->element);
        cur = cur->next;
    }

    return list_ret;
}

//new functions

void list_printElements(LinkedList* l1, LinkedList* l2) {
    if (list_isEmpty(l1) || list_isEmpty(l2))
        return;

    Node* cur = l2->head;
    Node* temp;
    int cont = 0;

    while (cur != NULL) {
        if (cur->element < l1->size && cur->element >= 0) {
            if (cont > 0)
                printf(" -> ");

            cont = 0;
            temp = l1->head;
            while (cont < cur->element) {
                temp = temp->next;
                cont++;
            }
            element_print(temp->element);
        }
        cur = cur->next;
    }
    printf("\n");
}

bool list_equals(LinkedList* l1, LinkedList* l2) {
    if (l1->size != l2->size)
        return false;

    Node* cur1 = l1->head;
    Node* cur2 = l2->head;

    while (cur1 != NULL) {
        if (cur1->element != cur2->element)
            return false;
        
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    return true;
}

int list_isSorted(LinkedList* l) {
    Node* cur = l->head;
    int contDecr = 0;
    int contCrec = 0;
    
    while (cur->next != NULL) {
        if (cur->element < cur->next->element)
            contCrec++;
        else if (cur->element > cur->next->element)
            contDecr++;
        
        cur = cur->next;
    }

    if (contDecr > 0 && contCrec > 0)
        return 0;
    else if (contCrec > 0)
        return 1;
    else
        return 2;
}

void list_removeDuplicates(LinkedList* l) {
    Node* cur = l->head;
    Node* aux;
    int cont = 0;
    int contAux;

    while (cur != NULL) {
        aux = cur->next;
        contAux = cont + 1;

        while (aux != NULL) {
            if (cur->element == aux->element) {
                aux = aux->next;
                list_removeAt(l, contAux);
                contAux = contAux - 1;
            } else {
                aux = aux->next;
            }
            
            contAux++;
        }

        cont++;
        cur = cur->next;
    }
}

void list_printReverse(LinkedList* l) {
    if (list_isEmpty(l) == true)
        return;
        
    Node* cur = l->head;
    Node* aux;
    int contPrint = l->size - 1;
    int contCur;

    while (cur != NULL) {
        if (contPrint == 0) {
            element_print(cur->element);
            break;
        }

        aux = cur;
        contCur = 0;
        while (contCur < contPrint) {
            aux = aux->next;
            contCur++;
        }
        element_print(aux->element);
        printf(" -> ");
        contPrint--;
    }
    printf("\n");
}