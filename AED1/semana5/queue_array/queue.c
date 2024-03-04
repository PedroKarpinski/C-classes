#include "queue.h"

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct Queue {
    Element* elements;
    int size;
    int capacity;
    int front;
    int back;
}

Queue* queue_create(int capacity) {
    Queue* queue = malloc(sizeof(Queue));

    queue->capacity = capacity;
    queue->elements = malloc(sizeof(Element) * capacity);
    queue->size = 0;
    queue->front = 0;
    queue->back = 0;

    return queue;
}

void queue_destroy(Queue* queue) {
    free(queue->elements);
    free(queue);
}

void queue_enqueue(Queue* queue, Element element) {

}

Element queue_dequeue(Queue* queue){
    
}

Element queue_front(Queue* queue) {
    if (queue_isEmpty(queue))
        return ELEMENT_NULL;    

    return queue->elements[queue->front];
}
Element queue_back(Queue* queue) {
    if (queue_isEmpty(queue))
        return ELEMENT_NULL;    

    return queue->elements[queue->back];
}

int queue_size(Queue* queue) {
    return queue->size;
}

bool queue_isEmpty(Queue* queue) {
    return queue->size == 0;
}
void queue_print(Queue* queue);