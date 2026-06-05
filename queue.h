
#ifndef QUEUE_H
#define QUEUE_H

typedef struct NodeAntrian {
    int idNasabah;
    struct NodeAntrian *next;
} NodeAntrian;

typedef struct {
    NodeAntrian *front;
    NodeAntrian *rear;
} Queue;

void initQueue(Queue *q);

int isEmpty(Queue *q);

void enqueue(Queue *q, int idNasabah);

int dequeue(Queue *q);

void displayQueue(Queue *q);

#endif
