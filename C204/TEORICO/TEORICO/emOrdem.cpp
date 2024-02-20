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


void emOrdem(treenodeptr raiz) { // posiciona a arvore em ordem
    if (raiz == NULL) {
        return;
    }

    emOrdem(raiz->direita);
    cout << raiz->data << " ";
    emOrdem(raiz->esquerda);
}

void destroyTree(Node* raiz) { //destroi a arvore e libera a memoria
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
    
    emOrdem(raiz);
    
    destroyTree(raiz);
    
    return 0;
}
