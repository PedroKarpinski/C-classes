#include <stdio.h>

#include "linked_list.h"

void test_insert() {
    LinkedList* list = list_create();

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);

    list_print(list);

    list_insertLast(list, 40);
    list_insertLast(list, 50);
    list_insertLast(list, 60);
    list_insertLast(list, 70);

    list_print(list);

    list_destroy(list);
}


int main() {
    test_insert();

    return 0;
}