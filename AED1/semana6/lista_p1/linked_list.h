#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "element.h"
#include <stdbool.h>

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);
void list_insertFirst(LinkedList* list, Element element);
void list_insertAfter(LinkedList* list, int pos, Element element);
void list_print(LinkedList* list);
bool list_removeFirst(LinkedList* list);
bool list_removeAt(LinkedList* list, int pos);
bool list_isEmpty(LinkedList* list);
int list_size(LinkedList* list);
Element list_element(LinkedList* list, int pos);
LinkedList* list_copy(LinkedList* list);

//new functions
void list_printElements(LinkedList* l1, LinkedList* l2);
bool list_equals(LinkedList* l1, LinkedList* l2);
int list_isSorted(LinkedList* l);
void list_removeDuplicates(LinkedList* l);
void list_printReverse(LinkedList* l);

#endif