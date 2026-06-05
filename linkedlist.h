#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct NodeTransaksi {
    int idTransaksi;
    char jenis[20];
    float jumlah;
    struct NodeTransaksi *next;
} NodeTransaksi;

// Deklarasi fungsi
void insertTransaksi(NodeTransaksi **head, int id, char jenis[], float jumlah);
NodeTransaksi* linearSearchTransaksi(NodeTransaksi *head, int id);
void tampilkanTransaksi(NodeTransaksi *head);

#endif
