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

treenodeptr removeValor(treenodeptr raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->data) {
        raiz->esquerda = removeValor(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = removeValor(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            treenodeptr temp = raiz->direita;
            delete raiz;
            return temp;
        } else if (raiz->direita == NULL) {
            treenodeptr temp = raiz->esquerda;
            delete raiz;
            return temp;
        }

        treenodeptr temp = raiz->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        raiz->data = temp->data;
        raiz->direita = removeValor(raiz->direita, temp->data);
    }
    return raiz;
}

void em_ordem(treenodeptr raiz) { //posiciona a arvore em ordem
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        cout << raiz->data << " ";
        em_ordem(raiz->direita);
    }
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
    int numero;

    while (true) {
        cin >> numero;
        if (numero == 0) {
            break;
        }
        raiz = inserirArvore(raiz, numero);
    }

    int A;
    cin >> A;

    raiz = removeValor(raiz, A);
    em_ordem(raiz);
    cout << endl;
    
    destroyTree(raiz);

    return 0;
}
