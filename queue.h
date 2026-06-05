
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

/* Inisialisasi queue */
void initQueue(Queue *q);

/* Cek queue kosong */
int isEmpty(Queue *q);

/* Tambah nasabah ke antrian */
void enqueue(Queue *q, int idNasabah);

/* Ambil nasabah terdepan */
int dequeue(Queue *q);

/* Tampilkan isi antrian */
void displayQueue(Queue *q);

#endif
