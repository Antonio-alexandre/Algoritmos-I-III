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

bool primo(int num) { //funcao para verificar se um numero eh primo
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int auxprimos(treenodeptr arvore) { //funcao auxiliar pra contar a quantidade de numeros primos
    if (arvore == NULL) return 0;

    int count = 0;
    if (primo(arvore->data)) {
        count = 1;
    }

    return count + auxprimos(arvore->esquerda) + auxprimos(arvore->direita);
}

int contaPrimos(treenodeptr arvore) { //contabiliza a quantidade de primos
    return auxprimos(arvore);
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
        if (numero == -1) {
            break;
        }
        raiz = inserirArvore(raiz, numero);
    }

    int numPrimos = contaPrimos(raiz);
    cout << numPrimos << " numeros primos" << endl;

	destroyTree(raiz);
	
    return 0;
}
