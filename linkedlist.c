#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// Menambah transaksi ke akhir linked list
void insertTransaksi(NodeTransaksi **head, int id, char jenis[], float jumlah) {
    NodeTransaksi *baru = (NodeTransaksi*)malloc(sizeof(NodeTransaksi));

    baru->idTransaksi = id;
    strcpy(baru->jenis, jenis);
    baru->jumlah = jumlah;
    baru->next = NULL;

    if (*head == NULL) {
        *head = baru;
        return;
    }

    NodeTransaksi *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = baru;
}

// Linear Search berdasarkan ID transaksi
NodeTransaksi* linearSearchTransaksi(NodeTransaksi *head, int id) {
    NodeTransaksi *temp = head;

    while (temp != NULL) {
        if (temp->idTransaksi == id) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

// Menampilkan seluruh transaksi
void tampilkanTransaksi(NodeTransaksi *head) {
    NodeTransaksi *temp = head;

    while (temp != NULL) {
        printf("ID: %d | Jenis: %s | Jumlah: %.2f\n",
               temp->idTransaksi,
               temp->jenis,
               temp->jumlah);

        temp = temp->next;
    }
}
