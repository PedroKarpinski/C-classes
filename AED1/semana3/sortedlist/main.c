#include <stdio.h>

#include "sorted_list.h"

int main(void) {
    SortedList* list = slist_create();

    bool i1 = slist_insert(list, 11, "joao", 10);
    bool i2 = slist_insert(list, 11, "joao", 10);
    bool i3 = slist_insert(list, 13, "joao", 10);
    bool i4 = slist_insert(list, 13, "joao", 10);
    bool i5 = slist_insert(list, 15, "joao", 10);
    bool i6 = slist_insert(list, 15, "joao", 10);

    printf("i1: %s\n", i1 ? "true" : "false");
    printf("i2: %s\n", i2 ? "true" : "false");
    printf("i3: %s\n", i3 ? "true" : "false");
    printf("i4: %s\n", i4 ? "true" : "false");
    printf("i5: %s\n", i5 ? "true" : "false");
    printf("i6: %s\n", i6 ? "true" : "false");

    slist_destroy(list);
    return 0;
}