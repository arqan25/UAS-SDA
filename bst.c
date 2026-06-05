#include "bst.h"

NodeNasabah* createNasabahNode(int id, char* nama){
    NodeNasabah* newNode = (NodeNasabah*)malloc(sizeof(NodeNasabah));
    if (newNode != NULL){
        newNode->idNasabah = id;
        strcpy(newNode->nama, nama);
        newNode->saldo = 0; 
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

NodeNasabah* insertNasabah (NodeNasabah* root, int id, char* nama){
    if (root == NULL){
        return createNasabahNode(id, nama);
    }
    if (id < root->idNasabah){
        root->left = insertNasabah(root->left, id, nama);
    }
    else if (id > root->idNasabah){
        root->right = insertNasabah(root->right, id, nama);
    }
    return root;
}

NodeNasabah* searchNasabah(NodeNasabah* root, int id){
    if (root == NULL || root->idNasabah == id){
        return root;
    }
    if (id < root->idNasabah){
        return searchNasabah(root->left, id);
    }
    return searchNasabah(root->right, id);
}
