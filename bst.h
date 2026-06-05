#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struktur data
typedef struct NodeNasabah{
    int idNasabah;
    char nama[50];
    int saldo;
    struct NodeNasabah *left, *right;
} NodeNasabah;

//deklarasi fungsi
NodeNasabah* insertNasabah(NodeNasabah* root, int id, char* nama);
NodeNasabah* searchNasabah(NodeNasabah* root, int id);

#endif