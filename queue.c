
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, int idNasabah) {

    NodeAntrian *newNode =
        (NodeAntrian *)malloc(sizeof(NodeAntrian));

    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }

    newNode->idNasabah = idNasabah;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {

    if (isEmpty(q)) {
        printf("Antrian kosong!\n");
        return -1;
    }

    NodeAntrian *temp = q->front;
    int id = temp->idNasabah;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return id;
}

void displayQueue(Queue *q) {

    if (isEmpty(q)) {
        printf("Antrian kosong.\n");
        return;
    }

    NodeAntrian *current = q->front;

    printf("\n=== Antrian Nasabah ===\n");

    while (current != NULL) {
        printf("ID Nasabah: %d\n", current->idNasabah);
        current = current->next;
    }
}
