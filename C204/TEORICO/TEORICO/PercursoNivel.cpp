#include <iostream>
#include <queue>
#include <locale.h>

using namespace std;

struct Node {
    int inteiro;
    Node* esquerda;
    Node* direita;
};

Node* criarNode(int valor) {
    Node* novoNode = new Node();
    novoNode->inteiro = valor;
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;
    return novoNode;
}

Node* inserir_arvore(Node* raiz, int valor) {
    if (raiz == NULL) {
        return criarNode(valor);
    }

    if (valor < raiz->inteiro) {
        raiz->esquerda = inserir_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->inteiro) {
        raiz->direita = inserir_arvore(raiz->direita, valor);
    }

    return raiz;
}

void levelOrderTraversal(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(raiz);

    while (!q.empty()) {
        Node* current = q.front();
        cout << current->inteiro << " ";
        if (current->esquerda != NULL) {
            q.push(current->esquerda);
        }
        if (current->direita != NULL) {
            q.push(current->direita);
        }
        q.pop();
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

    Node* raiz = NULL;
    int valor;

    cin >> valor;

    while (valor != -1) {
        raiz = inserir_arvore(raiz, valor);
        cin >> valor;
    }

    cout << "Percurso em nível:" << endl;
    levelOrderTraversal(raiz);
    cout << endl;

    destroyTree(raiz);

    return 0;
}
