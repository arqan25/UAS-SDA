#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Model Data Nasabah (untuk BST)
typedef struct NodeNasabah {
    int idNasabah;
    char nama[50];
    int saldo;
    struct NodeNasabah *left, *right;
} NodeNasabah;

// 2. Model Data Transaksi (untuk Linked List)
typedef struct NodeTransaksi {
    int idTransaksi;
    int idNasabah;
    char jenisSampah[30];
    float berat;
    int totalHarga;
    struct NodeTransaksi *next;
} NodeTransaksi;

// 3. Model Antrian (untuk Queue)
typedef struct NodeAntrian {
    int idNasabahAntrian;
    struct NodeAntrian *next;
} NodeAntrian;

typedef struct {
    NodeAntrian *front;
    NodeAntrian *rear;
} Queue;
