#include <iostream>
#include <locale.h>
using namespace std;

typedef struct torta
{
	double em;
	double p;
	double a;
	double d;
	int preco;
	int id;
	
} Torta;

struct Node {
    Torta data;
    Node* esquerda;
    Node* direita;
};

typedef Node* treenodeptr;

treenodeptr criaNode(Torta preco) {
    treenodeptr newNode = new Node;
    newNode->data = preco;
    newNode->esquerda = newNode->direita = NULL;
    return newNode;
}

treenodeptr inserirArvore(treenodeptr raiz, Torta preco) {
    if (raiz == NULL) {
        return criaNode(preco);
    }

    if (preco < raiz->data) {
        raiz->esquerda = inserirArvore(raiz->esquerda, preco);
    } else if (preco > raiz->data) {
        raiz->direita = inserirArvore(raiz->direita, preco);
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

void emOrdem(treenodeptr raiz) { // posiciona a arvore em ordem
    if (raiz == NULL) {
        return;
    }

    emOrdem(raiz->direita);
    cout << raiz->data.preco << ":" << data.id << " ";
    emOrdem(raiz->esquerda);
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
    
    Torta torta;
    int T;
    
    cin >> T;
    
    for(int i = 0; i < T; i++)
	{
		cin >> torta.em >> torta.p >> torta.a >> torta.d;
		
		torta.preco = (torta.em * torta.p * torta.a + torta.d + torta.a);
		torta.id = i;
		
		raiz = inserirArvore(raiz, torta.preco);
	}
	
	emOrdem(raiz);
	
    
    destroyTree(raiz);

    return 0;
}



