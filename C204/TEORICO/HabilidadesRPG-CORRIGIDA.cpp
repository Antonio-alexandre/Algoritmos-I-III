#include<iostream>
#include <locale.h>
#include<string>
#include <cstdlib>
using namespace std;


/*
	Considere o tipo abstrato de dados a seguir.
	Ele representa uma habilidade que pode ser usada por um personagem em um jogo de RPG.
	Habilidades são usadas para superar desafios no jogo.
	Desafios podem ser desafios mentais, físicos ou espirituais.
	Cada desafio tem um nível de dificuldade e para conseguir superá-lo, o personagem pode usar uma de suas habilidades.
	Quando a habilidade é usada, um valor aleatório de 1 a 20 é gerado e somado ao modificador da habilidade.
	Se o valor resultante for maio que o nível de dificuldade do desafio, o personagem consegue superá-lo.

	Cada habilidade tem um código único e uma descrição.
	Além disso é definido um atributo base (1: Mente, 2: Corpo ou 3: Espírito).
	Por fim é definido um modificador.

*/

string atributos_base[3] = {"Mental", "Físico", "Espiritual"};

typedef struct habilidade
{
	int codigo;
	string descricao;
	int atributo_base;
	int modificador;
} Habilidade;


struct Node
{
	Habilidade info; // info eh uma variavel do tipo habilidade
	Node * esquerda;
	Node * direita;
};

void inserir_habilidade(Node * &raiz, Habilidade h) // '&' só usa caso a gente queria fazer alguma alteracao na funcao princiapl
{
	if(raiz == NULL) // se a raiz eh nula ela cria um novo no
	{
		raiz = new Node; // alocando um no(endereco de memoria) na raiz, caso a raiz seja nula
		//(*raiz).info = h; // colocando habilidade na raiz
		raiz->info = h;
		raiz->esquerda = NULL;
		raiz->direita = NULL;
	}
	else
	{
		if(h.codigo < raiz->info.codigo)  // verificando se codigo da habilidade que to passando(h.codigo) é menor que o codigo da raiz(raiz->info.codigo) para alocar a esquerda
		{
			inserir_habilidade(raiz->esquerda, h); // verificando se a raiz da sub-arvore da esquerda eh nula ou nao atraves da recursividade, caso nao seja nulo ela cria 2 novos nodes, um a esquerda e outro a direita
		}
		else
		{
			inserir_habilidade(raiz->direita, h); // a raiz principal quando eu chamo recursivamente eh a da direita ou esquerda
		}
	}
}

// retornando um endereco de memoria da habilidade
Habilidade * buscar_habilidade(Node * raiz, int codigo_habilidade)
{
	if(raiz == NULL)
	{
		return NULL;
	}
	if(codigo_habilidade == raiz->info.codigo)
	{
		return &(raiz->info); // retornando o endereco da habilidade da raiz(usa '&' para apontar para o endereço, ja que a raiz nao é um ponteiro, ela está alocada em um endereço de memoria e através do endereço você pode acessar toas as infos do endereço)
	}
	if(codigo_habilidade < raiz->info.codigo)
	{
		return buscar_habilidade(raiz->esquerda, codigo_habilidade); // se o codigo for menor que o codigo da raiz a gente procura na esquerda da raiz
	}
	else
	{
		return buscar_habilidade(raiz->direita, codigo_habilidade); // se o codigo for maior que o codigo da raiz a gente procura na direita da raiz
	}
}

// typedef Node * Nodeptr;  serve para chamar "Node *" de Nodeptr

/*
	A função gera_desafio cria um desafio de um tipo aleatório e com um valor de dificuldade de 0 a 30.
*/

typedef struct desafio
{
	int dificuldade;
	int atributo_base;
} Desafio;

Desafio gerar_desafio()
{
	Desafio d;
	d.dificuldade = rand() % 30;
	d.atributo_base = rand() % 3;
	return d;
}

/*
	A função rolar_d20 cria um valor aleatório de 0 a 20 para ser somado ao modificador quando uma habilidade for usada.
*/

int rolar_d20()
{
	return rand() % 20;
}

/*
	Crie um sistema com as seguintes opções para o usuário: 1> Cadastrar nova habilidade e 2> Testar habilidades.

	Na opção 1, solicite que o usuário informe os dados sobre a habilidade a ser cadastrada.
	Aloque memória de forma dinâmica para cada uma dessas habilidades e adicione em uma estrutura de dados.

	Na opção 2, gere um desafio aleatório, usando a função gerar_desafio e apresente o tipo do desafio para o usuário.
	Em seguida, solicite que o usuário informe o código da habilidade a ser testada.
	Busque a habilidade na estrutura de dados.
	Por fim, verifique se a habilidade é do mesmo tipo de atributo base que o desafio.
	Se não for, apresente a mensagem "Essa habilidade não pode ser usada para esse desafio." e solicite para o usuário entrar com outra habilidade.
	Se for, gere um valor aleatório usando a função rolar_d20 e some com o modificador da habilidade.
	Se o valor resultante for maior ou igual ao valor da dificuldade do desafio, apresente a mensagem "Você superou esse desafio!".
	Senão, mostre a mensagem "Você fracassou nesse desafio...".


*/
int main()
{
	setlocale(LC_ALL, "");

	Node * raiz = NULL; // criando a raiz da arvóre

	cout << "Bem vindo ao sistema de habilidades.";

	int op = 4;

	do
	{
		cout << "\n\t\tMenu\n\t1> Cadastrar nova habilidade\n\t2> Testar habilidades\n\n\t3> Sair\n";



		do
		{
			cout << "Entre com a opção desejada: ";
			cin >> op;
			if(op != 1 && op != 2 && op != 3)
				cout << "Opção inválida!" << endl;
		}
		while(op != 1 && op != 2 && op != 3);

		if(op == 1)
		{
			// ----Cadastrar habilidade----
			cout << "\n\tCadastro de habilidade" << endl;
			//Solicitar dados da habilidade
			Habilidade h;
			cout << "Informe o codigo da habilidade: " << endl;
			cin >> h.codigo;
			cout << "Informe a descrição da habilidade: " << endl;
			cin >> h.descricao;vb
			cout << "Informe o atributo base da habilidade (1. Mental, 2. Fisico, 3. Espiritual): " << endl;
			cin >> h.atributo_base;
			h.atributo_base -= 1;
			cout << "Informe o modificador da habilidade: " << endl;
			cin >> h.modificador;
			// Alocar memória dinâmicamente
			// Adicionar na estrutura de dados

			inserir_habilidade(raiz, h); // chamando a função para inserir a habilidade

		}
		else if(op == 2)
		{
			cout << "\n\tTeste de habilidade" << endl;
			// -----Testar habilidade-----
			// Gerar desafio
			Desafio d = gerar_desafio();
			cout << "Desafio entrentado: " << atributos_base[d.atributo_base] << endl;
			cout << d.dificuldade << endl;

			// Escolher habilidade
			int habilidade;
			// Buscar habilidade na estrutura de dados
			
			Habilidade * resultado = NULL;
			do
			{
				cout << "Escolha a sua habilidade: ";
				cin >> habilidade;
				resultado = buscar_habilidade(raiz, habilidade); // buscando a habilidade na arvóre como ponteiro pq o retorno da função eh um poteiro
				
				// Verificar o atributo base da habilidade
				if(resultado == NULL || resultado->atributo_base != d.atributo_base)
				{
					cout<<"Habilidade inválida."<<endl;
				}
			}while(resultado == NULL || resultado->atributo_base != d.atributo_base) // while para verificar as condições para o usuario utilizar a habilidade
			

			// Rolar d20
			int valor_aleatorio = rolar_d20();

			// Somar com o modificador da habilidade
			int valor_total = valor_aleatorio + resultado->modificador;
			//Verificar se superou o desafio
			if(valor_aleatorio >= d.dificuldade){
				cout<<"Você superou o desafio"<<endl;
			}
			else{
				cout<<"Você fracassou nesse desafio"<<endl;
			}
		}
	}
	while(op != 3);

	cout << "Obrigado por utilizar o sistema de habilidades!" << endl;

	return 0;
}

/*
>>>>>>>>>>>>>>>Exemplo de uso:

Bem vindo ao sistema de habilidades.
                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 5
Opção inválida!
Entre com a opção desejada: 1

	   	Cadastro de Habilidade
Informe o código: 1
Informe a descrição: Chamas do patrono
Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): 3
Informe o modificador: 5

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 1

	   	Cadastro de Habilidade
Informe o código: 2
Informe a descrição: Escalada
Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): 3
Informe o modificador: 3

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 1

	   	Cadastro de Habilidade
Informe o código: 3
Informe a descrição: Conhecimento de história
Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): 3
Informe o modificador: 5

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 2

		Teste de habilidade
Desafio entrentado: Espiritual
Escolha a sua habilidade: 1
Você superou esse desafio!

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 2

		Teste de habilidade
Desafio entrentado: Físico
Escolha a sua habilidade: 1
Essa habilidade não pode ser usada para esse desafio.
Escolha a sua habilidade: 2
Você superou esse desafio!

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 2

		Teste de habilidade
Desafio entrentado: Mental
Escolha a sua habilidade: 3
Você fracassou nesse desafio...

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 3
Obrigado por utilizar o sistema de habilidades!


*/

