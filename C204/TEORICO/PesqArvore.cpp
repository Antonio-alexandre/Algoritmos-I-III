#include <iostream>
#include <locale.h>

using namespace std;

struct Node {
    int inteiro;
    Node* esquerda;
    Node* direita;
};

Node* criaNode(int valor) {
    Node* novoNode = new Node();
    novoNode->inteiro = valor;
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;
    return novoNode;
}

Node* inserir_arvore(Node* raiz, int valor) {
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

bool procura(Node* raiz, int valor) {
    if (raiz == NULL) {
        return false;
    }

    if (raiz->inteiro == valor) {
        return true;
    } else if (valor < raiz->inteiro) {
        return procura(raiz->esquerda, valor);
    } else {
        return procura(raiz->direita, valor);
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

    int N;
    cin >> N;

    Node* raiz = NULL;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (i == 0) {
            raiz = criaNode(num);
        } else {
            inserir_arvore(raiz, num);
        }
    }

    int X;
    cin >> X;

    if (procura(raiz, X)) {
        cout << "Encontrado\n";
    } else {
        cout << "Nao encontrado\n";
    }

    // Liberar memória alocada para a árvore
    destroyTree(raiz);

    return 0;
}
