#include <iostream>
#include <clocale> //Biblioteca para mudar o idioma que o compilador entende
using namespace std;

// Definindo a estrutura do nó da árvore
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Função para criar um novo nó na árvore
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para inserir um novo nó na árvore
Node* insert(Node* root, int data) {
    // Caso a raiz seja nula, criamos um novo nó com o dado fornecido
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Se o dado fornecido for menor que o dado da raiz, inserimos na subárvore esquerda
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    // Se o dado fornecido for maior que o dado da raiz, inserimos na subárvore direita
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função para imprimir a árvore em ordem
void emOrdem(Node* root) {
    if (root == NULL) {
        return;
    }
    emOrdem(root->left);
    cout << root->data << " ";
    emOrdem(root->right);
}

// Função para imprimir a árvore em pré-ordem
void preOrdem(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrdem(root->left);
    preOrdem(root->right);
}

// Função para imprimir a árvore em pós-ordem
void posOrdem(Node* root) {
    if (root == NULL) {
        return;
    }
    posOrdem(root->left);
    posOrdem(root->right);
    cout << root->data << " ";
}

int main() {
    //Adicionando a lingua portuguesa para podermos escrever "Árvore"
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    Node* root = NULL;

    // Inserindo elementos na árvore
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 4);
    
    // Imprimindo a árvore em pré-ordem
    preOrdem(root);
    cout << endl;

    // Imprimindo a árvore em ordem
    emOrdem(root);
    cout << endl;

    // Imprimindo a árvore em pós-ordem
    posOrdem(root);
    cout << endl;

    return 0;
}