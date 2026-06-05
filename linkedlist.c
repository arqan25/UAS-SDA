#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void insertTransaksi(NodeTransaksi **head,
                     int idTx,
                     int idNasabah,
                     char jenis[],
                     float berat,
                     int total)
{
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

NodeTransaksi* linearSearchTransaksi(NodeTransaksi *head, int idTx)
{
    NodeTransaksi *temp = head;

    while (temp != NULL) {
        if (temp->idTransaksi == idTx) {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void tampilkanTransaksi(NodeTransaksi *head)
{
    if (head == NULL) {
        printf("\n[INFO] Belum ada data transaksi yang tercatat.\n");
        return;
    }

    NodeTransaksi *temp = head;

    printf("====================================================================\n");
    printf(" ID TX     ID NASABAH     JENIS SAMPAH      BERAT       TOTAL HARGA\n");
    printf("====================================================================\n");

    while (temp != NULL) {
        printf(" TX%03d      %-14d %-17s %-5.2f kg    Rp%-10d\n",
               temp->idTransaksi,
               temp->idNasabah,
               temp->jenisSampah,
               temp->berat,
               temp->totalHarga);

        temp = temp->next;
    }

    printf("====================================================================\n");
}
