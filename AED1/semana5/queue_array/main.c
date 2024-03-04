#include <stdio.h>

#include "queue.h"

int main() {
    Queue* queue = queue_create();

    queue_enqueue(queue, 10);
    queue_enqueue(queue, 40);
    queue_enqueue(queue, 80);
    queue_enqueue(queue, 10);

    queue_print(queue);

    printf("vazia: %s\n", (queue_isEmpty(queue)) ? "true" : "false");
    queue_print(queue);

    printf(queue_dequeue(queue));
    queue_dequeue(queue);
    queue_dequeue(queue);

    queue_print(queue);

    queue_dequeue(queue);
    queue_dequeue(queue);
    printf("vazia: %s\n", (queue_isEmpty(queue)) ? "true" : "false");
    queue_print(queue);

    queue_destroy(queue);
}