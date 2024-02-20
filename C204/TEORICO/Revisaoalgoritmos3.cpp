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
	int l; // contador                                       // instruções: 1  custo: 1
	int cont = 0; // verifica se foi encontrado o aluno      // instruções: 2  custo: 2
	for(l = 0; l < quant; l++)                               // instruções: quant + 1   custo: quant + 1
	{
		if(mat == info.matricula[l])                         // instruções: 1  custo: 1
		{
			cont = l;                                        // instruções: 1  custo: 1 ou custo: 2 quando a atribuição acontece
			break;                                           // instruções: 1  custo: 1
		}
		else
		{
			l++;                                             // instruções: 1  custo: 2
		}
	}
	if(cont == l)                                            // instruções: 1  custo: 1
	{
		cout << info.nome[cont] << endl;                     // instruções: 1  custo: 1
		cout << info.matricula[cont] << endl;                // instruções: 1  custo: 1
		cout << info.nascimento[cont] << endl;               // instruções: 1  custo: 1
	}
	else
	{
		cout << "Aluno nao localizado" << endl;              // instruções: 1  custo: 1
	}
}

void procuranome(string name, int quant, dados info)
{
	int l; // contador                                       // instruções: 1  custo: 1
	int cont = 0; // verifica se foi encontrado o aluno      // instruções: 2  custo: 2
	for(l = 0; l < quant; l++)                               // instruções: quant + 1   custo: quant + 1
	{
		if((name.compare(info.nome[l])) == 0)                // instruções: 1  custo: 1
		{
			cont = l;                                        // instruções: 1  custo: 1 ou custo: 2 quando a atribuição acontece
			break;                                           // instruções: 1  custo: 1
		}
		else
		{
			l++;                                             // instruções: 1  custo: 2
		}
	}
	if(cont == l)                                            // instruções: 1  custo: 1
	{
		cout << info.nome[cont] << endl;                     // instruções: 1  custo: 1
		cout << info.matricula[cont] << endl;                // instruções: 1  custo: 1
		cout << info.nascimento[cont] << endl;               // instruções: 1  custo: 1
	}
	else
	{
		cout << "Aluno nao localizado" << endl;              // instruções: 1  custo: 1
	}
}

void quantosAlunosComIdade(int idade, int quant, dados info) {
	int l; // contador                                                        // instruções: 1  custo: 1
	int cont = 0;                                                             // instruções: 1  custo: 2
	// Iremos assumir que a data de nascimento esta no formato "YYYY-MM-DD"   
	int anoAtual = 2023; // mude baseado no ano atual                         // instruções: 1  custo: 2
	for(l = 0; l < quant; l++){                                               // instruções: quant + 1   custo: quant + 1
		int nascimento;                                                       // instruções: 1  custo: 1
		stringstream yearStream(info.nascimento[l].substr(0,4));              // instruções: 1  custo: 3
		yearStream >> nascimento;                                             // instruções: 1  custo: 1
		if(anoAtual - nascimento <= idade) {                                  // instruções: 1  custo: 2
			cont++;                                                           // instruções: 1  custo: 2
		}
	}
	cout << "quantidade de alunos com mais ou menos a idade pedida: " << cont << endl; // instruções: 1  custo: 1
}

int main()
{
	dados aluno;                                                              
	int N; // quantidade de alunos                      // instruções: 1  custo: 1
	int i; // contador                                  // instruções: 1  custo: 1 
    int opcao; // opcao = 1: pesquisa por matricula , opcao = 2: pesquisa por nome opcao = 3: quantos alunos tem essa idade  // instruções: 1  custo: 1
	int mat; // procurar informacoes de aluno por matricula                // instruções: 1  custo: 1
	int idade; // procurar quantos alunos tem essa idade                   // instruções: 1  custo: 1
	string name; // procurar informacoes de aluno por nome                 // instruções: 1  custo: 1

    cout << "quantidade de alunos a serem cadastrados: ";                  // instruções: 1  custo: 1
	cin >> N;                                                              // instruções: 1  custo: 1

	for(i = 0; i < N; i++)                                                 // instruções: N + 1  custo: N + 1
	{
		cout << "nome do aluno: ";                                         // instruções: 1  custo: 1
		cin.ignore();                                                      // instruções: 1  custo: 1
		getline(cin, aluno.nome[i]);                                       // instruções: 1  custo: 1
		cout << "matricula do aluno: ";                                    // instruções: 1  custo: 1
		cin >> aluno.matricula[i];                                         // instruções: 1  custo: 1
		cout << "data de nascimento do aluno(YYYY-MM-DD): ";               // instruções: 1  custo: 1
		cin.ignore();                                                      // instruções: 1  custo: 1
		getline(cin , aluno.nascimento[i]);                                // instruções: 1  custo: 1
	}
	cout << "opcao 1 = pesquisa por matricula, opcao 2 = pesquisa por nome, opcao 3 = procurar quantos possuem a idade desejada ou menor" << endl;  // instruções: 1  custo: 1
	cin >> opcao;                                                          // instruções: 1  custo: 1

	if(opcao == 1)                                                         // instruções: 1  custo: 1
	{
		cout << "matricula a ser pesquisada no sistema: ";                 // instruções: 1  custo: 1
		cin >> mat;                                                        // instruções: 1  custo: 1
		procuramat(mat, N, aluno);                                         // instruções: 1  custo: 1
	}

	if(opcao == 2)                                                         // instruções: 1  custo: 1
	{
		cout << "nome a ser pesquisado no sistema: ";                      // instruções: 1  custo: 1
		cin.ignore();                                                      // instruções: 1  custo: 1
		getline(cin, name);                                                // instruções: 1  custo: 1
		procuranome(name, N, aluno);                                       // instruções: 1  custo: 1
	}
	if(opcao == 3)                                                         // instruções: 1  custo: 1
    {
		cout << "indique a idade a ser procurada entre os alunos: ";       // instruções: 1  custo: 1
		cin >> idade;                                                      // instruções: 1  custo: 1
		quantosAlunosComIdade(idade, N, aluno);                            // instruções: 1  custo: 1
	}

	return 0;
}


