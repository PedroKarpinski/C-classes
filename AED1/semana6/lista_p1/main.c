#include "linked_list.h"
#include "stack.h"
#include "queue.h"

#include <stdio.h>

void ex1() {
    LinkedList* l1 = list_create();
    list_insertFirst(l1, 5);
    list_insertFirst(l1, 80);
    list_insertFirst(l1, 10);
    list_insertFirst(l1, 40);
    list_insertFirst(l1, 30);

    LinkedList* l2 = list_create();
    list_insertFirst(l2, 4);
    list_insertFirst(l2, 3);
    list_insertFirst(l2, 1);

    list_printElements(l1, l2);

    list_destroy(l1);
    list_destroy(l2);
}

void ex2() {
    LinkedList* l1 = list_create();
    list_insertFirst(l1, 1);
    list_insertFirst(l1, 2);
    list_insertFirst(l1, 3);

    LinkedList* l2 = list_create();
    list_insertFirst(l2, 1);
    list_insertFirst(l2, 2);
    list_insertFirst(l2, 3);

    printf("l1 = l2 -> %s\n", list_equals(l1, l2) ? "true" : "false");

    list_destroy(l1);
    list_destroy(l2);
}

void ex3() {
    //decrescente
    LinkedList* l1 = list_create();
    list_insertFirst(l1, 1);
    list_insertFirst(l1, 2);
    list_insertFirst(l1, 3);
    list_insertFirst(l1, 3);
    list_insertFirst(l1, 4);
    printf("l1 = %d\n", list_isSorted(l1));

    //crescente
    LinkedList* l2 = list_create();
    list_insertFirst(l2, 4);
    list_insertFirst(l2, 3);
    list_insertFirst(l2, 3);
    list_insertFirst(l2, 2);
    list_insertFirst(l2, 1);
    printf("l2 = %d\n", list_isSorted(l2));

    //desordenada
    LinkedList* l3 = list_create();
    list_insertFirst(l3, 4);
    list_insertFirst(l3, 1);
    list_insertFirst(l3, 3);
    list_insertFirst(l3, 3);
    list_insertFirst(l3, 2);
    printf("l3 = %d\n", list_isSorted(l3));

    list_destroy(l1);
    list_destroy(l2);
    list_destroy(l3);
}

void ex4() {
    LinkedList* l1 = list_create();

    list_insertFirst(l1, 3);
    list_insertFirst(l1, 3);
    list_insertFirst(l1, 4);
    list_insertFirst(l1, 3);
    list_insertFirst(l1, 4);
    list_insertFirst(l1, 4);
    list_insertFirst(l1, 4);
    list_insertFirst(l1, 3);

    list_print(l1);
    list_removeDuplicates(l1);
    list_print(l1);

    list_destroy(l1);
}

void ex5() {
    LinkedList* l1 = list_create();

    list_insertFirst(l1, 5); 
    list_insertFirst(l1, 4); 
    list_insertFirst(l1, 3); 
    list_insertFirst(l1, 2); 
    list_insertFirst(l1, 1); 

    list_printReverse(l1);

    list_destroy(l1);
}

LinkedList* list_reverse(LinkedList* l) {
    LinkedList* list_ret = list_copy(l);
    
    for (int i = 0; i <= list_size(l); i++) {
        list_insertAfter(list_ret, list_size(list_ret) - i, list_element(list_ret, 0));
        list_removeFirst(list_ret);
    }

    return list_ret;
}

void ex6() {
    LinkedList* l1 = list_create();
    list_insertFirst(l1, 5);
    list_insertFirst(l1, 4);
    list_insertFirst(l1, 3);
    list_insertFirst(l1, 2);
    list_insertFirst(l1, 1);
    printf("lista 1 = ");
    list_print(l1);

    LinkedList* l2 = list_reverse(l1);
    printf("lista 1 = ");
    list_print(l1);
    printf("lista 2 = ");
    list_print(l2);

    list_destroy(l1);
    list_destroy(l2);
}

Stack* stack_copy(Stack* s) {
    Stack* new = stack_create();

    for (int i = stack_size(s) - 1; i >= 0; i--)
        stack_push(new, stack_peek_pos(s, i));

    return new;
}

void ex7() {
    Stack* s1 = stack_create();
    stack_push(s1, 5);
    stack_push(s1, 4);
    stack_push(s1, 3);
    stack_push(s1, 2);
    stack_push(s1, 1);
    printf("pilha 1 = ");
    stack_print(s1);

    Stack* s2 = stack_copy(s1);
    printf("pilha 2 = ");
    stack_print(s2);

    stack_destroy(s1);
    stack_destroy(s2);
}

Queue* queue_reverse(Stack* s) {
    Queue* new = queue_create();

    for (int i = stack_size(s) - 1; i >= 0; i--)
        queue_enqueue(new, stack_peek_pos(s, i));
    
    return new;
}

void ex8() {
    Stack* stack = stack_create();
    stack_push(stack, 5);
    stack_push(stack, 4);
    stack_push(stack, 3);
    stack_push(stack, 2);
    stack_push(stack, 1);
    printf("pilha = ");
    stack_print(stack);

    Queue* queue = queue_reverse(stack);
    printf("fila = ");
    queue_print(queue);

    stack_destroy(stack);
    queue_destroy(queue);
}

bool queue_equals(Queue* q1, Queue* q2) {
    if (queue_size(q1) != queue_size(q2))
        return false;
    
    for (int i = 0; i < queue_size(q1); i++)
        if (queue_peek_pos(q1, i) != queue_peek_pos(q2, i))
            return false;

    return true;
}

void ex9() {
    Queue* q1 = queue_create();
    queue_enqueue(q1, 1);
    queue_enqueue(q1, 2);
    queue_enqueue(q1, 3);

    Queue* q2 = queue_create();
    queue_enqueue(q2, 1);
    queue_enqueue(q2, 2);
    queue_enqueue(q2, 3);

    Queue* q3 = queue_create();
    queue_enqueue(q3, 1);
    queue_enqueue(q3, 3);
    queue_enqueue(q3, 2);

    printf("fila 1 = fila 2: %s\n", queue_equals(q1, q2) ? "true" : "false");
    printf("fila 1 = fila 3: %s\n", queue_equals(q1, q3) ? "true" : "false");
    printf("fila 2 = fila 3: %s\n", queue_equals(q2, q3) ? "true" : "false");

    queue_destroy(q1);
    queue_destroy(q2);
    queue_destroy(q3);
}

bool isBalanced(char* expr) {
    int abrePar = 0, fechaPar = 0;
    int abreCha = 0, fechaCha = 0;
    int abreCol = 0, fechaCol = 0;

    int i = 0;
    char aux = expr[i];
    while (aux != '\0') {
        if (aux == '[')
            abreCol++;
        if (aux == ']')
            fechaCol++;

        if (aux == '(')
            abrePar++;
        if (aux == ')')
            fechaPar++;

        if (aux == '{')
            abreCha++;
        if (aux == '}')
            fechaCha++;

        aux = expr[++i];
    }

    if (abrePar != fechaPar || abreCol != fechaCol || abreCha != fechaCha)
        return false;
    else
        return true;
}

void ex10() {
    printf("[2 * (3 + 4)] %s\n", isBalanced("[2 * (3 + 4)]") ? "é balanceada" : "não é balanceada");
    printf("[2 * (3 + 4))) %s\n", isBalanced("[2 * (3 + 4)))") ? "é balanceada" : "não é balanceada");
    printf("[2 * (3 + 4)} %s\n", isBalanced("[2 * (3 + 4)}") ? "é balanceada" : "não é balanceada");
}

int main() {
    ex10();

    return 0;
}