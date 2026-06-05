#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct NodeTransaksi {
    int idTransaksi;
    int idNasabah;
    char jenisSampah[30];
    float berat;
    int totalHarga;
    struct NodeTransaksi *next;
} NodeTransaksi;

void insertTransaksi(NodeTransaksi **head, int idTx, int idNasabah, char jenis[], float berat, int total);
NodeTransaksi* linearSearchTransaksi(NodeTransaksi *head, int idTx);
void tampilkanTransaksi(NodeTransaksi *head);

#endif
