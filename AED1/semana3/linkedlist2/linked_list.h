#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "element.h"
#include <stdbool.h>

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);
void list_insertFirst(LinkedList* list, Element element);
void list_insertLast(LinkedList* list, Element element);
void list_insertAfter(LinkedList* list, int pos, Element element);
void list_print(LinkedList* list);
bool list_removeFirst(LinkedList* list);
bool list_removeAt(LinkedList* list, int pos);

#endif