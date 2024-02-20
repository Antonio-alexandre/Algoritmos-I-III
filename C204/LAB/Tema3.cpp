#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;



// Definição da estrutura do nó da árvore
struct Node {
    string nome;
    string propriedadeMagica;
    int identificacao;
    string cor;
    int nivelForca;
    int pontos[2];

    Node* esquerda;
    Node* direita;

    Node(string n, string pm, int id, string c, int nf, int pontosX, int pontosY)
        : nome(n), propriedadeMagica(pm), identificacao(id), cor(c), nivelForca(nf) {
            pontos[0] = pontosX;
            pontos[1] = pontosY;
            esquerda = direita = NULL;
        }
};
typedef Node * Nodeptr;

// Função para inserir um item na árvore
Node* inserir(Node* raiz, string nome, string propriedadeMagica, string cor, int pontosX, int pontosY, int nivelForca, int identificacao = 1) {
    if (raiz == NULL) {
        return new Node(nome, propriedadeMagica, identificacao, cor, nivelForca, pontosX, pontosY);
    }

    // Verifica se o item pode passar pela abertura da bolsa
    if ((pontosX * pontosX + pontosY * pontosY) <= 400) {
        // Insere na subárvore esquerda se o nome for menor
        if (nome.compare(raiz->nome) < 0) {
            raiz->esquerda = inserir(raiz->esquerda, nome, propriedadeMagica, cor, pontosX, pontosY, identificacao, nivelForca);
        }
        // Insere na subárvore direita se o nome for maior
        else if (nome.compare(raiz->nome) > 0) {
            raiz->direita = inserir(raiz->direita, nome, propriedadeMagica, cor, pontosX, pontosY, identificacao, nivelForca);
        }
        // Se o nome for igual, atualiza a identificação e não insere (evita duplicatas)
        else {
            raiz->identificacao++;
        }
    }

    return raiz;
}

// Função para buscar um item pelo nome
void buscarPorNome(Node* raiz, string nome) {
    if (raiz == NULL) {
        cout << "Item não encontrado!" << endl;
        return;
    }

    if (nome.compare(raiz->nome) == 0) {
        cout << "Item encontrado!" << endl;
    } else if (nome.compare(raiz->nome) < 0) {
        buscarPorNome(raiz->esquerda, nome);
    } else {
        buscarPorNome(raiz->direita, nome);
    }
}

// Função para armazenar as propriedades mágicas e depois imprimir em ordem alfabética
void armazenarPropriedades(Nodeptr raiz, vector<string>& propriedades)
{
    if (raiz == NULL)
    {
        return;
    }

    armazenarPropriedades(raiz->esquerda, propriedades);
    propriedades.push_back(raiz->info.propriedade_magica); // Armazena a propriedade mágica no vetor
    armazenarPropriedades(raiz->direita, propriedades);
}

// Função auxiliar para ordenar e imprimir as propriedades mágicas em ordem alfabética
void ordenarImprimirPropriedades(Nodeptr raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    vector<string> propriedades;
    armazenarPropriedades(raiz, propriedades);

    // Ordena as propriedades mágicas em ordem alfabética
    sort(propriedades.begin(), propriedades.end());

    // Imprime as propriedades mágicas ordenadas
    for (const string& propriedade : propriedades)
    {
        cout << propriedade << endl;
    }
}

// Função para contar a quantidade de itens com as mesmas propriedades mágicas
int contarMesmasPropriedades(Node* raiz, string propriedadeMagica) {
    if (raiz == NULL) {
        return 0;
    }

    int cont = 0;
    if (propriedadeMagica.compare(raiz->propriedadeMagica) == 0) {
        cont++;
    }

    cont += contarMesmasPropriedades(raiz->esquerda, propriedadeMagica);
    cont += contarMesmasPropriedades(raiz->direita, propriedadeMagica);

    return cont;
}

// Função para remover itens de uma determinada cor
Node* removerPorCor(Node* raiz, string cor) {
    if (raiz == NULL) {
        return NULL;
    }

    // Remove recursivamente da subárvore esquerda e direita
    raiz->esquerda = removerPorCor(raiz->esquerda, cor);
    raiz->direita = removerPorCor(raiz->direita, cor);

    // Se a cor do nó atual for a cor a ser removida, libera o nó
    if (cor.compare(raiz->cor) == 0) {
        delete raiz;
        return NULL; // Retorna NULL para ajustar o ponteiro do pai
    }

    return raiz;
}

// Função para encontrar o percurso até um item de uma cor específica
string encontrarPercursoPorCor(Node* raiz, string cor) {
    if (raiz == NULL) {
        return "";
    }

    if (cor.compare(raiz->cor) == 0) {
        return "emOrdem";
    }

    string percursoEsquerda = encontrarPercursoPorCor(raiz->esquerda, cor);
    if (!percursoEsquerda.empty()) {
        return "préOrdem";
    }

    string percursoDireita = encontrarPercursoPorCor(raiz->direita, cor);
    if (!percursoDireita.empty()) {
        return "pósOrdem";
    }

    return "";
}

// Função para imprimir em ordem (inOrder)
void emOrdem(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    emOrdem(raiz->esquerda);
    cout << "Nome: " << raiz->nome << ", Propriedade Mágica: " << raiz->propriedadeMagica
         << ", Identificação: " << raiz->identificacao << ", Cor: " << raiz->cor
         << ", Nível de Força: " << raiz->nivelForca << endl;
    emOrdem(raiz->direita);
}

// Função para imprimir em pré-ordem (preOrder)
void preOrdem(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    cout << "Nome: " << raiz->nome << ", Propriedade Mágica: " << raiz->propriedadeMagica
         << ", Identificação: " << raiz->identificacao << ", Cor: " << raiz->cor
         << ", Nível de Força: " << raiz->nivelForca << endl;
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

// Função para imprimir em pós-ordem (postOrder)
void posOrdem(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    cout << "Nome: " << raiz->nome << ", Propriedade Mágica: " << raiz->propriedadeMagica
         << ", Identificação: " << raiz->identificacao << ", Cor: " << raiz->cor
         << ", Nível de Força: " << raiz->nivelForca << endl;
}

int main() {
    setlocale(LC_ALL, "");

    Node* raiz = NULL;

    char opcao;
    do {
        cout << "Escolha uma opção:\n"
             << "1. Inserir item\n"
             << "2. Buscar item por nome\n"
             << "3. Ordenar e imprimir propriedades mágicas\n"
             << "4. Contar itens com a mesma propriedade mágica\n"
             << "5. Remover itens por cor\n"
             << "6. Encontrar percurso por cor\n"
             << "7. Imprimir em ordem\n"
             << "8. Imprimir em pré-ordem\n"
             << "9. Imprimir em pós-ordem\n"
             << "0. Sair\n";

        cin >> opcao;

        switch (opcao) {
            case '1': {
                string nome, propriedadeMagica, cor;
                int pontosX, pontosY, forca;
                cout << "Digite o nome do item: ";
                cin >> nome;
                cout << "Digite a propriedade mágica do item: ";
                cin >> propriedadeMagica;
                cout << "Digite a cor do item: ";
                cin >> cor;
                cout << "Digita a força do item(1-Fraco, 2-Moderado, 3-Excelente): ";
                cin >> forca;
                cout << "Digite as coordenadas do item (x y): ";
                cin >> pontosX >> pontosY;

                raiz = inserir(raiz, nome, propriedadeMagica, cor, pontosX, pontosY, forca);
                break;
            }
            case '2': {
                string nomeBusca;
                cout << "Digite o nome do item a ser buscado: ";
                cin >> nomeBusca;
                buscarPorNome(raiz, nomeBusca);
                break;
            }
            case '3': {
                cout << "Propriedades mágicas ordenadas:\n";
                ordenarImprimirPropriedades(raiz);
                break;
            }
            case '4': {
                string propMagicaContagem;
                cout << "Digite a propriedade mágica para contar itens: ";
                cin >> propMagicaContagem;
                cout << "Quantidade de itens com a propriedade mágica "
                     << propMagicaContagem << ": "
                     << contarMesmasPropriedades(raiz, propMagicaContagem) << endl;
                break;
            }
            case '5': {
                string corRemover;
                cout << "Digite a cor dos itens a serem removidos: ";
                cin >> corRemover;
                raiz = removerPorCor(raiz, corRemover);
                cout << "Itens da cor " << corRemover << " removidos." << endl;
                break;
            }
            case '6': {
                string corPercurso;
                cout << "Digite a cor do item para encontrar o percurso: ";
                cin >> corPercurso;
                string percurso = encontrarPercursoPorCor(raiz, corPercurso);
                if (percurso.empty()) {
                    cout << "Item não encontrado!" << endl;
                } else {
                    cout << "Percurso para encontrar item da cor " << corPercurso << ": " << percurso << endl;
                }
                break;
            }
            case '7': {
                cout << "Imprimir em ordem:\n";
                emOrdem(raiz);
                break;
            }
            case '8': {
                cout << "Imprimir em pré-ordem:\n";
                preOrdem(raiz);
                break;
            }
            case '9': {
                cout << "Imprimir em pós-ordem:\n";
                posOrdem(raiz);
                break;
            }
            case '0':
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != '0');

    // Libera a memória alocada
    delete raiz;

    return 0;
}
