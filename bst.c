#include "bst.h"

//fungsi yang akan membantu untuk mengalokasikan memori node nasabah baru
NodeNasabah* createNasabahNode(int id, char* nama){
    NodeNasabah* newNode = (NodeNasabah*)malloc(sizeof(NodeNasabah));
    if (newNode != NULL){
        newNode->idNasabah = id;
        strcpy(newNode->nama, nama);
        newNode->saldo = 0; //saldo awal nasabah baru
        newNode->left = NULL;
        newNode->right= NULL;
    }
    return newNode;
}