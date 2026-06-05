#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void insertTransaksi(NodeTransaksi **head, int idTx, int idNasabah, char jenis[], float berat, int total) {
    NodeTransaksi *baru = (NodeTransaksi*)malloc(sizeof(NodeTransaksi));

    baru->idTransaksi = idTx;
    baru->idNasabah = idNasabah;
    strcpy(baru->jenisSampah, jenis);
    baru->berat = berat;
    baru->totalHarga = total;
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

NodeTransaksi* linearSearchTransaksi(NodeTransaksi *head, int idTx) {
    NodeTransaksi *temp = head;
    while (temp != NULL) {
        if (temp->idTransaksi == idTx) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void tampilkanTransaksi(NodeTransaksi *head) {
    NodeTransaksi *temp = head;
    while (temp != NULL) {
        printf("ID Tx: %d | ID Nasabah: %d | Jenis: %s | Berat: %.2f kg | Total: Rp%d\n",
               temp->idTransaksi, temp->idNasabah, temp->jenisSampah, temp->berat, temp->totalHarga);
        temp = temp->next;
    }
}
