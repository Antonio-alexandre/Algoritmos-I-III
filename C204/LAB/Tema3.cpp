#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;



// Defini��o da estrutura do n� da �rvore
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

// Fun��o para inserir um item na �rvore
Node* inserir(Node* raiz, string nome, string propriedadeMagica, string cor, int pontosX, int pontosY, int nivelForca, int identificacao = 1) {
    if (raiz == NULL) {
        return new Node(nome, propriedadeMagica, identificacao, cor, nivelForca, pontosX, pontosY);
    }

    // Verifica se o item pode passar pela abertura da bolsa
    if ((pontosX * pontosX + pontosY * pontosY) <= 400) {
        // Insere na sub�rvore esquerda se o nome for menor
        if (nome.compare(raiz->nome) < 0) {
            raiz->esquerda = inserir(raiz->esquerda, nome, propriedadeMagica, cor, pontosX, pontosY, identificacao, nivelForca);
        }
        // Insere na sub�rvore direita se o nome for maior
        else if (nome.compare(raiz->nome) > 0) {
            raiz->direita = inserir(raiz->direita, nome, propriedadeMagica, cor, pontosX, pontosY, identificacao, nivelForca);
        }
        // Se o nome for igual, atualiza a identifica��o e n�o insere (evita duplicatas)
        else {
            raiz->identificacao++;
        }
    }

    return raiz;
}

// Fun��o para buscar um item pelo nome
void buscarPorNome(Node* raiz, string nome) {
    if (raiz == NULL) {
        cout << "Item n�o encontrado!" << endl;
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

// Fun��o para armazenar as propriedades m�gicas e depois imprimir em ordem alfab�tica
void armazenarPropriedades(Nodeptr raiz, vector<string>& propriedades)
{
    if (raiz == NULL)
    {
        return;
    }

    armazenarPropriedades(raiz->esquerda, propriedades);
    propriedades.push_back(raiz->info.propriedade_magica); // Armazena a propriedade m�gica no vetor
    armazenarPropriedades(raiz->direita, propriedades);
}

// Fun��o auxiliar para ordenar e imprimir as propriedades m�gicas em ordem alfab�tica
void ordenarImprimirPropriedades(Nodeptr raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    vector<string> propriedades;
    armazenarPropriedades(raiz, propriedades);

    // Ordena as propriedades m�gicas em ordem alfab�tica
    sort(propriedades.begin(), propriedades.end());

    // Imprime as propriedades m�gicas ordenadas
    for (const string& propriedade : propriedades)
    {
        cout << propriedade << endl;
    }
}

// Fun��o para contar a quantidade de itens com as mesmas propriedades m�gicas
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

// Fun��o para remover itens de uma determinada cor
Node* removerPorCor(Node* raiz, string cor) {
    if (raiz == NULL) {
        return NULL;
    }

    // Remove recursivamente da sub�rvore esquerda e direita
    raiz->esquerda = removerPorCor(raiz->esquerda, cor);
    raiz->direita = removerPorCor(raiz->direita, cor);

    // Se a cor do n� atual for a cor a ser removida, libera o n�
    if (cor.compare(raiz->cor) == 0) {
        delete raiz;
        return NULL; // Retorna NULL para ajustar o ponteiro do pai
    }

    return raiz;
}

// Fun��o para encontrar o percurso at� um item de uma cor espec�fica
string encontrarPercursoPorCor(Node* raiz, string cor) {
    if (raiz == NULL) {
        return "";
    }

    if (cor.compare(raiz->cor) == 0) {
        return "emOrdem";
    }

    string percursoEsquerda = encontrarPercursoPorCor(raiz->esquerda, cor);
    if (!percursoEsquerda.empty()) {
        return "pr�Ordem";
    }

    string percursoDireita = encontrarPercursoPorCor(raiz->direita, cor);
    if (!percursoDireita.empty()) {
        return "p�sOrdem";
    }

    return "";
}

// Fun��o para imprimir em ordem (inOrder)
void emOrdem(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    emOrdem(raiz->esquerda);
    cout << "Nome: " << raiz->nome << ", Propriedade M�gica: " << raiz->propriedadeMagica
         << ", Identifica��o: " << raiz->identificacao << ", Cor: " << raiz->cor
         << ", N�vel de For�a: " << raiz->nivelForca << endl;
    emOrdem(raiz->direita);
}

// Fun��o para imprimir em pr�-ordem (preOrder)
void preOrdem(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    cout << "Nome: " << raiz->nome << ", Propriedade M�gica: " << raiz->propriedadeMagica
         << ", Identifica��o: " << raiz->identificacao << ", Cor: " << raiz->cor
         << ", N�vel de For�a: " << raiz->nivelForca << endl;
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

// Fun��o para imprimir em p�s-ordem (postOrder)
void posOrdem(Node* raiz) {
    if (raiz == NULL) {
        return;
    }

    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    cout << "Nome: " << raiz->nome << ", Propriedade M�gica: " << raiz->propriedadeMagica
         << ", Identifica��o: " << raiz->identificacao << ", Cor: " << raiz->cor
         << ", N�vel de For�a: " << raiz->nivelForca << endl;
}

int main() {
    setlocale(LC_ALL, "");

    Node* raiz = NULL;

    char opcao;
    do {
        cout << "Escolha uma op��o:\n"
             << "1. Inserir item\n"
             << "2. Buscar item por nome\n"
             << "3. Ordenar e imprimir propriedades m�gicas\n"
             << "4. Contar itens com a mesma propriedade m�gica\n"
             << "5. Remover itens por cor\n"
             << "6. Encontrar percurso por cor\n"
             << "7. Imprimir em ordem\n"
             << "8. Imprimir em pr�-ordem\n"
             << "9. Imprimir em p�s-ordem\n"
             << "0. Sair\n";

        cin >> opcao;

        switch (opcao) {
            case '1': {
                string nome, propriedadeMagica, cor;
                int pontosX, pontosY, forca;
                cout << "Digite o nome do item: ";
                cin >> nome;
                cout << "Digite a propriedade m�gica do item: ";
                cin >> propriedadeMagica;
                cout << "Digite a cor do item: ";
                cin >> cor;
                cout << "Digita a for�a do item(1-Fraco, 2-Moderado, 3-Excelente): ";
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
                cout << "Propriedades m�gicas ordenadas:\n";
                ordenarImprimirPropriedades(raiz);
                break;
            }
            case '4': {
                string propMagicaContagem;
                cout << "Digite a propriedade m�gica para contar itens: ";
                cin >> propMagicaContagem;
                cout << "Quantidade de itens com a propriedade m�gica "
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
                    cout << "Item n�o encontrado!" << endl;
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
                cout << "Imprimir em pr�-ordem:\n";
                preOrdem(raiz);
                break;
            }
            case '9': {
                cout << "Imprimir em p�s-ordem:\n";
                posOrdem(raiz);
                break;
            }
            case '0':
                break;
            default:
                cout << "Op��o inv�lida! Tente novamente.\n";
        }
    } while (opcao != '0');

    // Libera a mem�ria alocada
    delete raiz;

    return 0;
}
