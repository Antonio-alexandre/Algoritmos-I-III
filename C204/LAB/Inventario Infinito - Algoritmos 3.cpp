#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

struct reta
{
	ponto A;
	ponto B;
};
typedef reta segmento;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

/*
Posicao de C em relacao ao segmento AB
1 -> esquerda
-1 -> direita
0 -> colinear
*/
int sentido(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float vet;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	vet = vetorial(AB, AC);
	if(vet > 0)
		return 1;
	else if(vet < 0)
		return -1;
	else
		return 0;
}

// Os pontos devem estar ordenados pelo angulo
// O poligono deve ser convexo
// Retorna a area do poligono
float area_poligono(ponto v[], int n)
{
	float area = 0;
	for(int i = 0; i < n - 2; i++)
	{
		area = area + area_triangulo(v[0], v[i + 1], v[i + 2]);
	}
	return area;
}

// funcao para comparar dois pontos durante a ordenacao
bool cmp(ponto a, ponto b)
{
	// atan2((a.y - 0),(a.x - 0)) -> arco tangente[(a.y - 0)/(a.x - 0)]
	float angA = atan2(a.y, a.x);
	float angB = atan2(b.y, b.x);
	if(angA == angB) // se os angulos forem iguais, desempata pelo mais longe
	{
		float distA = sqrt(pow(a.x, 2) + pow(a.y, 2)); // raiz[(a.x - 0)^2 + (a.y - 0)^2]
		float distB = sqrt(pow(b.x, 2) + pow(b.y, 2)); // raiz[(b.x - 0)^2 + (b.y - 0)^2]
		return distA > distB; // primeiro o de maior distancia
	}
	else
		return angA < angB; // primeiro o de menor angulo
}

// funcao para ordenar os pontos de acordo com o angulo formado com a horizontal
void ordena_pelo_angulo(ponto p[], int n)
{
	ponto pivot; // será o ponto mais abaixo
	int pos_pivot;
	// encontro o ponto mais abaixo para ser o pivot
	pivot = p[0];
	pos_pivot = 0;
	for(int i = 1; i < n; i++)
	{
		if(p[i].y < pivot.y)
		{
			pivot = p[i];
			pos_pivot = i;
		}
		else if(p[i].y == pivot.y && p[i].x < pivot.x)
		{
			pivot = p[i];
			pos_pivot = i;
		}
	}

	// coloca o pivot na posicao 0 do vetor
	p[pos_pivot] = p[0];
	p[0] = pivot;

	// desloca o pivot para (0,0), e os demais pontos em relacao ao pivot
	for(int i = 0; i < n; i++)
	{
		p[i].x -= pivot.x;
		p[i].y -= pivot.y;
	}

	// ordenacao
	sort(p + 1, p + n, cmp);

	// desloca os pontos de volta a posicao original
	for(int i = 0; i < n; i++)
	{
		p[i].x += pivot.x;
		p[i].y += pivot.y;
	}
}

// penultimo da pilha
ponto next_to_top(list <ponto> pilha)
{
	pilha.pop_back();
	return pilha.back();
}

// Encontra o fecho convexo de um conjunto de pontos
// retorna uma lista com os pontos que compoem o fecho convexo
list <ponto> Graham_scan(ponto p[], int n)
{
	list <ponto> pilha;

	ordena_pelo_angulo(p, n);

	pilha.push_back(p[0]);
	pilha.push_back(p[1]);
	pilha.push_back(p[2]);
	int i = 3;
	while(i < n)
	{
		// curva a esquerda, adiciona
		if(sentido(next_to_top(pilha), pilha.back(), p[i]) == 1)
		{
			pilha.push_back(p[i]);
			i++;
		}
		// curva a direita (ou mesma linha), remove
		else
			pilha.pop_back();
	}
	return pilha;
}

// struct item para salvar os dados dos itens
typedef struct item
{
	string nome;
	string propriedade_magica;
	int id;
	string nivel_forca;
	string cor;
} Item;

// struct node cria a arvore binaria
struct Node
{
	Item info;
	Node * esquerda;
	Node * direita;
};
typedef Node * Nodeptr;

// função para buscar item na árvore
Item * buscar_item(Nodeptr raiz, string nome_item)
{
	if(raiz == NULL)
	{
		return NULL;
	}
	if(nome_item.compare(raiz->info.nome) == 0)
	{
		return &(raiz->info);
	}
	if(nome_item.compare(raiz->info.nome) < 0)
	{
		return buscar_item(raiz->esquerda, nome_item);
	}
	else
	{
		return buscar_item(raiz->direita, nome_item);
	}
}

// função para imprimir os itens em ordem alfabética
void imprimir(Nodeptr raiz)
{
	if (raiz == NULL)
	{
		return;
	}
	imprimir(raiz->esquerda);
	cout << "Nome: " << raiz->info.nome << endl;
	cout << "Propriedade magica: " << raiz->info.propriedade_magica << endl;
	cout << "id: " << raiz->info.id << endl;
	cout << "Nivel de forca: " << raiz->info.nivel_forca << endl;
	cout << "Cor: " << raiz->info.cor << endl;
	cout << " " << endl;
	imprimir(raiz->direita);
}

// função que insere os itens na árvore
void inserir_item(Nodeptr &raiz, Item i, ponto p[], int q)
{
	if(area_poligono(p, q) < 40)
	{
		if(i.nivel_forca.compare("Fraco") == 0 || i.nivel_forca.compare("Moderado") == 0 || i.nivel_forca.compare("Excelente") == 0)
		{
			if(raiz == NULL)
			{
				raiz = new Node;
				raiz->info = i;
				raiz->esquerda = NULL;
				raiz->direita = NULL;
			}
			else
			{
				if (i.nome.compare(raiz->info.nome) < 0)
				{
					inserir_item(raiz->esquerda, i, p, q);
				}
				// Insere na subárvore direita se o nome for maior
				else if (i.nome.compare(raiz->info.nome) > 0)
				{
					inserir_item(raiz->direita, i, p, q);
				}
			}
		}
		else
		{
			cout << "Nível de força inválido!\n" << endl;
		}
	}
	else
	{
		cout << "O item nao entra na bolsa!\n" << endl;
	}
}



// Funcao para armazenar as propriedades magicas e depois imprimir em ordem alfabetica
void armazenarPropriedades(Nodeptr raiz, vector<string>& propriedades)
{
	if (raiz == NULL)
	{
		return;
	}

	armazenarPropriedades(raiz->esquerda, propriedades);
	propriedades.push_back(raiz->info.propriedade_magica); // Armazena a propriedade magica no vetor
	armazenarPropriedades(raiz->direita, propriedades);
}

// função para imprimir as propriedades em odem alfabética
void ordenarImprimirPropriedades(Nodeptr raiz)
{
	if (raiz == NULL)
	{
		return;
	}

	vector<string> propriedades;
	armazenarPropriedades(raiz, propriedades);

	// Ordena as propriedades mágicas em ordem alfabetica
	sort(propriedades.begin(), propriedades.end());

	// Imprime as propriedades magicas ordenadas
	ordenarImprimirPropriedades(raiz->esquerda);
	cout << "Propriedade mágica: " << raiz->info.propriedade_magica << endl;
	ordenarImprimirPropriedades(raiz->direita);
}

// função para contar quantos itens tem a mesma propriedade magica
int contarMesmasPropriedades(Nodeptr raiz, string propriedadeMagica)
{
	if (raiz == NULL)
	{
		return 0;
	}

	int cont = 0;

	if (propriedadeMagica.compare(raiz->info.propriedade_magica) == 0)
	{
		cont++;
	}

	cont += contarMesmasPropriedades(raiz->esquerda, propriedadeMagica);
	cont += contarMesmasPropriedades(raiz->direita, propriedadeMagica);

	return cont;
}

// função para encontrar o menor valor a direita
Nodeptr encontrar_redir_menor(Nodeptr &raiz)
{
	if(raiz == NULL)
		return NULL;
	Nodeptr menor;
	if(raiz->esquerda == NULL)
	{
		menor = raiz;
		raiz = raiz->direita;
		return menor;
	}
	else
	{
		return encontrar_redir_menor(raiz->esquerda);
	}
}
// função para remover itens de determinada cor
bool removerPorCor(Nodeptr &raiz, string cor)
{
	if(raiz == NULL)
		return false;
	if(cor.compare(raiz->info.cor) == 0)
	{
		Nodeptr p = raiz;
		if(raiz->esquerda == NULL)
		{
			raiz = raiz->direita;
		}
		else
		{
			if(raiz->direita == NULL)
			{
				raiz = raiz->esquerda;
			}
			else
			{
				p = encontrar_redir_menor(raiz->direita);
				raiz->info = p->info;
			}
		}
		delete p;
		return true;
	}
	else
	{
		if(cor.compare(raiz->info.cor) == 0)
			return removerPorCor(raiz->esquerda, cor);
		else
			return removerPorCor(raiz->direita, cor);
	}
}

// função para encontrar o menor caminho para achar um determinada cor
string encontrarPercursoPorCor(Nodeptr raiz, string cor)
{
	if (raiz == NULL)
	{
		return "";
	}

	if (cor.compare(raiz->info.cor) == 0)
	{
		return "emOrdem";
	}

	string percursoEsquerda = encontrarPercursoPorCor(raiz->esquerda, cor);
	if (!percursoEsquerda.empty())
	{
		return "préOrdem";
	}

	string percursoDireita = encontrarPercursoPorCor(raiz->direita, cor);
	if (!percursoDireita.empty())
	{
		return "pósOrdem";
	}

	return "";
}

// Função para destruir a árvore binária
void destroyTree(Nodeptr raiz)
{
	if (raiz == NULL)
	{
		return;
	}

	destroyTree(raiz->esquerda);
	destroyTree(raiz->direita);
	delete raiz;
}

int main()
{
	setlocale(LC_ALL, "");

	Nodeptr raiz = NULL;

	ponto p[100]; // pontos do poligono convexo;
	int q = 0; // quantidade de pontos do poligono convexo
	list <ponto> fecho_convexo;

	int op;
	float x, y;
	int auxID = 1;


	cout << "Bem vindo!" << endl;
	do
	{
		cout << "Selecione uma opção: \n1- Colocar item na bolsa \n2- Verificar se o item existe"
			 << "\n3- Imprimir os itens em ordem alfabética das propriedades mágicas \n4- Mostrar a quantidade de itens de uma determidada propriedade mágica"
			 << "\n5- Remover todos os elementos de uma determinada cor"
			 << "\n6- Descobrir por qual percurso (emOrdem, pósOrdem e préOrdem) encontra primeiro o item da cor procurada \n7- Sair" << endl;
		do
		{
			cin >> op;
			if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7)
			{
				cout << "Opção inválida!\n Selecione outra opção" << endl;
			}
		}
		while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7);

		if(op == 1)
		{
			Item i;
			i.id = auxID;
			cout << "Informações do item" << endl;
			cin.ignore();
			cout << "Nome: ";
			getline(cin, i.nome);
			cout << "Propriedade mágica: ";
			getline(cin, i.propriedade_magica);
			cout << "Nível de força (Fraco, Moderado, Excelente): ";
			getline(cin, i.nivel_forca);
			cout << "Cor: ";
			getline(cin, i.cor);
			cout << "x y(caso 0 0 contorno é finalizado): ";
			bool controle = true;
			while(controle)
			{
				for(int i = 0; i < 1;) // for termina quando x = 0 e y = 0
				{
					cin >> x >> y;
					if(x != 0 || y != 0)
					{
						p[q].x = x;
						p[q].y = y;
						q++;
					}
					else
					{
						controle = false;
						break;
					}
				}
			}
			fecho_convexo = Graham_scan(p, q);

			inserir_item(raiz, i, p, q); // chamando a função para inserir item na árvore
			imprimir(raiz); // chamando a função para imprimir os itens em ordem alfabética
			auxID++;
			for(int j = 0; j < q; j++) // voltando os valores dos pontos para 0
			{
				p[q].x = 0;
				p[q].y = 0;
			}
			q = 0; // reseta a quantidade de pontos do fecho convexo para 0
		}
		if(op == 2)
		{
			string nome_busca; // string para auxiliar a busca do nome
			Item * resultado = NULL;
			cout << "Insira o nome do item a ser buscado: ";
			cin.ignore();
			getline(cin, nome_busca);
			resultado = buscar_item(raiz, nome_busca); // chamando a função para buscar o item desejado
			if(resultado == NULL)
			{
				cout << "Item não encontrado\n" << endl;
			}
			else
			{
				cout << "Item encontrado\n" << endl;
			}
		}
		if(op == 3)
		{
			cout << "Propriedades mágicas ordenadas:\n";
			ordenarImprimirPropriedades(raiz); // chamando a função que imprimi as propriedades mágicas ordenadas em ordem alfabética
		}
		if(op == 4)
		{
			string pMagica; // string para auxiliar a busca da propriedade mágica
			cout << "Digite a propriedade mágica: ";
			cin.ignore();
			getline(cin, pMagica);
			cout << "Quantidade de itens com a propriedade mágica " << pMagica << ": " << contarMesmasPropriedades(raiz, pMagica) << endl; // chamando e mostrando a função que conta a quantidade de propriedades mágicas iguais
		}
		if(op == 5)
		{
			string corRemover; // string para auxiliar a busca da cor a ser removida
			cout << "Digite a cor dos itens a serem removidos: ";
			cin.ignore();
			getline(cin, corRemover);
			for(int j = 0; j <= auxID; j++)
			{
				removerPorCor(raiz, corRemover); // removendo a cor através da função removerPorCor
			}
			cout << "Itens da cor " << corRemover << " removidos." << endl;
		}
		if(op == 6)
		{
			string corPercurso; // string auxiliar para a busca do percurso da cor
			cout << "Digite a cor do item para encontrar o percurso: ";
			cin.ignore();
			getline(cin, corPercurso);
			string percurso = encontrarPercursoPorCor(raiz, corPercurso); // encontrando o menor percurso pra cor desejada e atribuindo o resultado na string
			if (percurso.empty())
			{
				cout << "Item não encontrado!\n" << endl;
			}
			else
			{
				cout << "Percurso para encontrar item da cor " << corPercurso << ": " << percurso << endl;
			}
		}
	}
	while(op != 7);

	// destruindo a arvore
	destroyTree(raiz);

	return 0;
}
