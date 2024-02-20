#include <iostream>
#include <locale.h>
#include <iomanip>
using namespace std;

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

float somaElementos(treenodeptr arvore) {
    if (arvore == NULL) {
        return 0;
    }

    return arvore->inteiro + somaElementos(arvore->esquerda) + somaElementos(arvore->direita);
}

int contarElementos(treenodeptr arvore) {
    if (arvore == NULL) {
        return 0;
    }

    return 1 + contarElementos(arvore->esquerda) + contarElementos(arvore->direita);
}

float media(treenodeptr arvore) {
    float soma = somaElementos(arvore);
    int quantidade = contarElementos(arvore);

    if (quantidade == 0) {
        return 0; // Evita divisão por zero
    }

    return soma / quantidade;
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

    float resultado = media(raiz);
    cout << "Media: " << fixed << setprecision(2) << resultado << endl;

	destroyTree(raiz);
    return 0;
}
