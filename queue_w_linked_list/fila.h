#ifndef QUEUE_LINKED_LIST
#define QUEUE_LINKED_LIST

#define  true 1
#define false 0

typedef struct node Node;
typedef struct queue Queue;

Queue* queue_create(int size);
void queue_free(Queue* queue);
void queue_enqueue(Queue* queue, int value);
int queue_dequeue(Queue* queue);
int queue_first(Queue* queue);
int queue_last(Queue* queue);
int queue_is_empty(Queue* queue);

#endif // !QUEUE_LINKED_LIST
