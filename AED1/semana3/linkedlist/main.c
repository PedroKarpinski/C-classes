#include <stdio.h>

#include "linked_list.h"

void test_insert() {
    LinkedList* list = list_create();

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);

    list_print(list);

    list_insertAfter(list, 1, 40);
    list_insertAfter(list, -1, 50);
    list_insertAfter(list, 25, 60);
    list_insertAfter(list, 0, 70);

    list_print(list);

    list_destroy(list);
}

void test_removeFirst() {
    LinkedList* list = list_create();

    bool res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");

    list_insertFirst(list, 30);
    list_insertFirst(list, 20);
    list_insertFirst(list, 40);
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    
    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");

    list_destroy(list);
}

void test_removeAt() {
    LinkedList* list = list_create();

    bool res = list_removeAt(list, 0);
    printf("%s\n", (res) ? "true" : "false");

    list_insertFirst(list, 30);
    list_insertFirst(list, 20);
    list_insertFirst(list, 40);
    list_print(list);

    res = list_removeAt(list, -1);
    printf("%s\n", (res) ? "true" : "false");
    res = list_removeAt(list, 10);
    printf("%s\n", (res) ? "true" : "false");

    res = list_removeAt(list, 1);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 1);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 0);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 0);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    list_destroy(list);
}

int main() {
    test_removeAt();

    return 0;
}