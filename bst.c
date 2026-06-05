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
//fungsi untuk memasukkan data nasabah baru
NodeNasabah* insertNasabah (NodeNasabah* root, int id, char* nama){
    if (root == NULL){
        return createNasabahNode(id, nama);
    }
    //jika id lebih kecil, masuk ke kiri
    if (id < root->idNasabah){
        root->left = insertNasabah(root->left, id, nama);
    }
    //jika id lebih besar, masuk ke kanan
    else if (id > root->idNasabah){
        root->right = insertNasabah(root->right, id, nama);
    }
    return root;
}