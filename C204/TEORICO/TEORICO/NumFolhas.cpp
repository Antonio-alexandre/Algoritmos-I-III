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


int contaFolhas(treenodeptr arvore) { //conta a quantidade de folhas na arvore
    if (arvore == NULL) {
        return 0;
    }

    if (arvore->esquerda == NULL && arvore->direita == NULL) {
        return 1;
    }

    return contaFolhas(arvore->esquerda) + contaFolhas(arvore->direita);
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

    int quantFolhas = contaFolhas(raiz);
    cout << quantFolhas << endl;
    
    destroyTree(raiz);
    
    return 0;
}
