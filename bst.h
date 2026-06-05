#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeNasabah {
    int idNasabah;
    char nama[50];
    int saldo;
    struct NodeNasabah *left, *right;
} NodeNasabah;

NodeNasabah* createNasabahNode(int id, char* nama);
NodeNasabah* insertNasabah(NodeNasabah* root, int id, char* nama);
NodeNasabah* searchNasabah(NodeNasabah* root, int id);

#endif
