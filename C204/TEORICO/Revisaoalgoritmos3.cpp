#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define max 100

struct dados
{
	string nome[max];
	int matricula[max];
	string nascimento[max];

};

void procuramat(int mat, int quant, dados info)
{
	int l; // contador                                       // instru��es: 1  custo: 1
	int cont = 0; // verifica se foi encontrado o aluno      // instru��es: 2  custo: 2
	for(l = 0; l < quant; l++)                               // instru��es: quant + 1   custo: quant + 1
	{
		if(mat == info.matricula[l])                         // instru��es: 1  custo: 1
		{
			cont = l;                                        // instru��es: 1  custo: 1 ou custo: 2 quando a atribui��o acontece
			break;                                           // instru��es: 1  custo: 1
		}
		else
		{
			l++;                                             // instru��es: 1  custo: 2
		}
	}
	if(cont == l)                                            // instru��es: 1  custo: 1
	{
		cout << info.nome[cont] << endl;                     // instru��es: 1  custo: 1
		cout << info.matricula[cont] << endl;                // instru��es: 1  custo: 1
		cout << info.nascimento[cont] << endl;               // instru��es: 1  custo: 1
	}
	else
	{
		cout << "Aluno nao localizado" << endl;              // instru��es: 1  custo: 1
	}
}

void procuranome(string name, int quant, dados info)
{
	int l; // contador                                       // instru��es: 1  custo: 1
	int cont = 0; // verifica se foi encontrado o aluno      // instru��es: 2  custo: 2
	for(l = 0; l < quant; l++)                               // instru��es: quant + 1   custo: quant + 1
	{
		if((name.compare(info.nome[l])) == 0)                // instru��es: 1  custo: 1
		{
			cont = l;                                        // instru��es: 1  custo: 1 ou custo: 2 quando a atribui��o acontece
			break;                                           // instru��es: 1  custo: 1
		}
		else
		{
			l++;                                             // instru��es: 1  custo: 2
		}
	}
	if(cont == l)                                            // instru��es: 1  custo: 1
	{
		cout << info.nome[cont] << endl;                     // instru��es: 1  custo: 1
		cout << info.matricula[cont] << endl;                // instru��es: 1  custo: 1
		cout << info.nascimento[cont] << endl;               // instru��es: 1  custo: 1
	}
	else
	{
		cout << "Aluno nao localizado" << endl;              // instru��es: 1  custo: 1
	}
}

void quantosAlunosComIdade(int idade, int quant, dados info) {
	int l; // contador                                                        // instru��es: 1  custo: 1
	int cont = 0;                                                             // instru��es: 1  custo: 2
	// Iremos assumir que a data de nascimento esta no formato "YYYY-MM-DD"   
	int anoAtual = 2023; // mude baseado no ano atual                         // instru��es: 1  custo: 2
	for(l = 0; l < quant; l++){                                               // instru��es: quant + 1   custo: quant + 1
		int nascimento;                                                       // instru��es: 1  custo: 1
		stringstream yearStream(info.nascimento[l].substr(0,4));              // instru��es: 1  custo: 3
		yearStream >> nascimento;                                             // instru��es: 1  custo: 1
		if(anoAtual - nascimento <= idade) {                                  // instru��es: 1  custo: 2
			cont++;                                                           // instru��es: 1  custo: 2
		}
	}
	cout << "quantidade de alunos com mais ou menos a idade pedida: " << cont << endl; // instru��es: 1  custo: 1
}

int main()
{
	dados aluno;                                                              
	int N; // quantidade de alunos                      // instru��es: 1  custo: 1
	int i; // contador                                  // instru��es: 1  custo: 1 
    int opcao; // opcao = 1: pesquisa por matricula , opcao = 2: pesquisa por nome opcao = 3: quantos alunos tem essa idade  // instru��es: 1  custo: 1
	int mat; // procurar informacoes de aluno por matricula                // instru��es: 1  custo: 1
	int idade; // procurar quantos alunos tem essa idade                   // instru��es: 1  custo: 1
	string name; // procurar informacoes de aluno por nome                 // instru��es: 1  custo: 1

    cout << "quantidade de alunos a serem cadastrados: ";                  // instru��es: 1  custo: 1
	cin >> N;                                                              // instru��es: 1  custo: 1

	for(i = 0; i < N; i++)                                                 // instru��es: N + 1  custo: N + 1
	{
		cout << "nome do aluno: ";                                         // instru��es: 1  custo: 1
		cin.ignore();                                                      // instru��es: 1  custo: 1
		getline(cin, aluno.nome[i]);                                       // instru��es: 1  custo: 1
		cout << "matricula do aluno: ";                                    // instru��es: 1  custo: 1
		cin >> aluno.matricula[i];                                         // instru��es: 1  custo: 1
		cout << "data de nascimento do aluno(YYYY-MM-DD): ";               // instru��es: 1  custo: 1
		cin.ignore();                                                      // instru��es: 1  custo: 1
		getline(cin , aluno.nascimento[i]);                                // instru��es: 1  custo: 1
	}
	cout << "opcao 1 = pesquisa por matricula, opcao 2 = pesquisa por nome, opcao 3 = procurar quantos possuem a idade desejada ou menor" << endl;  // instru��es: 1  custo: 1
	cin >> opcao;                                                          // instru��es: 1  custo: 1

	if(opcao == 1)                                                         // instru��es: 1  custo: 1
	{
		cout << "matricula a ser pesquisada no sistema: ";                 // instru��es: 1  custo: 1
		cin >> mat;                                                        // instru��es: 1  custo: 1
		procuramat(mat, N, aluno);                                         // instru��es: 1  custo: 1
	}

	if(opcao == 2)                                                         // instru��es: 1  custo: 1
	{
		cout << "nome a ser pesquisado no sistema: ";                      // instru��es: 1  custo: 1
		cin.ignore();                                                      // instru��es: 1  custo: 1
		getline(cin, name);                                                // instru��es: 1  custo: 1
		procuranome(name, N, aluno);                                       // instru��es: 1  custo: 1
	}
	if(opcao == 3)                                                         // instru��es: 1  custo: 1
    {
		cout << "indique a idade a ser procurada entre os alunos: ";       // instru��es: 1  custo: 1
		cin >> idade;                                                      // instru��es: 1  custo: 1
		quantosAlunosComIdade(idade, N, aluno);                            // instru��es: 1  custo: 1
	}

	return 0;
}


