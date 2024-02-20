#include <iostream>
#include <clocale> //Biblioteca para mudar o idioma que o compilador entende
using namespace std;

// Definindo a estrutura do n� da �rvore
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fun��o para criar um novo n� na �rvore
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fun��o para inserir um novo n� na �rvore
Node* insert(Node* root, int data) {
    // Caso a raiz seja nula, criamos um novo n� com o dado fornecido
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Se o dado fornecido for menor que o dado da raiz, inserimos na sub�rvore esquerda
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    // Se o dado fornecido for maior que o dado da raiz, inserimos na sub�rvore direita
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Fun��o para imprimir a �rvore em ordem
void emOrdem(Node* root) {
    if (root == NULL) {
        return;
    }
    emOrdem(root->left);
    cout << root->data << " ";
    emOrdem(root->right);
}

// Fun��o para imprimir a �rvore em pr�-ordem
void preOrdem(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrdem(root->left);
    preOrdem(root->right);
}

// Fun��o para imprimir a �rvore em p�s-ordem
void posOrdem(Node* root) {
    if (root == NULL) {
        return;
    }
    posOrdem(root->left);
    posOrdem(root->right);
    cout << root->data << " ";
}

int main() {
    //Adicionando a lingua portuguesa para podermos escrever "�rvore"
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    Node* root = NULL;

    // Inserindo elementos na �rvore
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 4);
    
    // Imprimindo a �rvore em pr�-ordem
    preOrdem(root);
    cout << endl;

    // Imprimindo a �rvore em ordem
    emOrdem(root);
    cout << endl;

    // Imprimindo a �rvore em p�s-ordem
    posOrdem(root);
    cout << endl;

    return 0;
}