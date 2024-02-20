#include <iostream>
#include <locale.h>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node* esquerda;
    Node* direita;
};

typedef Node* treenodeptr;

treenodeptr criaNode(int value) {
    treenodeptr newNode = new Node;
    newNode->data = value;
    newNode->esquerda = newNode->direita = NULL;
    return newNode;
}

treenodeptr inserirArvore(treenodeptr raiz, int num) {
    if (raiz == NULL) {
        return criaNode(num);
    }

    if (num < raiz->data) {
        raiz->esquerda = inserirArvore(raiz->esquerda, num);
    } else if (num > raiz->data) {
        raiz->direita = inserirArvore(raiz->direita, num);
    }

    return raiz;
}


bool buscarCidade(treenodeptr raiz, int cidade) {
    if (raiz == NULL) {
        return false;
    }

    if (cidade == raiz->data) {
        return true;
    } else if (cidade < raiz->data) {
        return buscarCidade(raiz->esquerda, cidade);
    } else {
        return buscarCidade(raiz->direita, cidade);
    }
}

void preOrdem(treenodeptr raiz, int cidade, string &caminho) { //verifica se o menor caminho eh em ordem
    if (raiz != NULL) {
        if (raiz->data == cidade) {
            caminho = "Pre";
            return;
        }
        preOrdem(raiz->esquerda, cidade, caminho);
        preOrdem(raiz->direita, cidade, caminho);
    }
}

void emOrdem(treenodeptr raiz, int cidade, string &caminho) { //verifica se o menor caminho eh pre ordem
    if (raiz != NULL) {
        emOrdem(raiz->esquerda, cidade, caminho);
        if (raiz->data == cidade && caminho != "Pre") {
            caminho = "Em";
            return;
        }
        emOrdem(raiz->direita, cidade, caminho);
    }
}

void posOrdem(treenodeptr raiz, int cidade, string &caminho) { //verifica se o menor caminho eh pos ordem
    if (raiz != NULL) { 
        posOrdem(raiz->esquerda, cidade, caminho);
        posOrdem(raiz->direita, cidade, caminho);
        if (raiz->data == cidade && caminho != "Pre" && caminho != "Em") {
            caminho = "Pos";
            return;
        }
    }
}

void destroyTree(Node* raiz) { //destroi a arvore e libera memoria
    if (raiz != NULL) {
        destroyTree(raiz->esquerda);
        destroyTree(raiz->direita);
        delete raiz;
    }
}

int main() {
    setlocale(LC_ALL, "");

    treenodeptr raiz = NULL;
    int numero;

    while (true) {
        cin >> numero;
        if (numero == -1) {
            break;
        }
        raiz = inserirArvore(raiz, numero);
    }

    int cidadeA;
    cin >> cidadeA;

    string caminho = ""; //menor caminho
    
    preOrdem(raiz, cidadeA, caminho);
    
    if (caminho.empty()) {
        caminho = "Em";
        emOrdem(raiz, cidadeA, caminho);
    }
    if (caminho.empty()) {
        caminho = "Pos";
        posOrdem(raiz, cidadeA, caminho);
    }

    cout << caminho << endl;
    
    destroyTree(raiz);

    return 0;
}
