#include <iostream>
#include <locale.h>
#include <iomanip>
using namespace std;
#define INT_MAX 999
#define INT_MIN 0

struct Node {
    int inteiro;
    Node* esquerda;
    Node* direita;
};

typedef Node* treenodeptr;

treenodeptr criaNode(int valor) {
    treenodeptr novoNode = new Node;
    novoNode->inteiro = valor;
    novoNode->esquerda = novoNode->direita = NULL;
    return novoNode;
}

treenodeptr inserir_arvore(treenodeptr raiz, int valor) {
    if (raiz == NULL) {
        return criaNode(valor);
    }

    if (valor < raiz->inteiro) {
        raiz->esquerda = inserir_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->inteiro) {
        raiz->direita = inserir_arvore(raiz->direita, valor);
    }

    return raiz;
}


int maior(treenodeptr arvore) {
    if (arvore == NULL) {
        // Valor invalido para indicar que a arvore esta vazia
        return INT_MIN;
    }

    while (arvore->direita != NULL) {
        arvore = arvore->direita;
    }

    return arvore->inteiro;
}

int menor(treenodeptr arvore) {
    if (arvore == NULL) {
        // Valor invalido para indicar que a arvore esta vazia
        return INT_MAX;
    }

    while (arvore->esquerda != NULL) {
        arvore = arvore->esquerda;
    }

    return arvore->inteiro;
}

void destroyTree(Node* raiz) {
    if (raiz != NULL) {
        destroyTree(raiz->esquerda);
        destroyTree(raiz->direita);
        delete raiz;
    }
}

int main() {
    setlocale(LC_ALL, "");

    treenodeptr raiz = NULL;
    int num;

    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        raiz = inserir_arvore(raiz, num);
    }
    
    cout << menor(raiz) << " e " << maior(raiz);
    
    destroyTree(raiz);
    
    return 0;
}
