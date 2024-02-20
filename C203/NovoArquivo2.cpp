#include <iostream>
#include <cstring>

using namespace std;

struct dado
{
	char info[50];
	int k;
	int status;
};

int h1(int k, int m)
{
	int resultado_h1; // variavel para guardar o resultado de k mod m

	resultado_h1 = k % m; // conta para saber o resto de k/m
	if(resultado_h1 < 0)  // if para nao deixar o valor negativo, pois nao existe posicao negativa no vetor
		resultado_h1 += m;

	return resultado_h1; // retornar o valor de da operacao acima
}

int h2(int k, int m)
{
	int resultado_h2; // variavel para guardar o resultado de 1+(k mod (m-1))

	resultado_h2 = 1 + (k % (m - 1)); // conta para saber o resultado de 1+(k mod (m-1))
	if(resultado_h2 < 0)			// if para nao deixar o valor negativo, pois nao existe posicao negativa no vetor
		resultado_h2 += m;

	return resultado_h2; // retornar o valor de da operacao acima
}

int dhash(int k, int m, int i)
{
	int hash1 = h1(k, m); // variavel para puxar o resultado da funcao h1
	int hash2 = h2(k, m); // variavel para puxar o resultado da funcao h2
	int resultado;	  // variavel para armazenar a posicao do objeto na tabela

	resultado = (hash1 + (i * hash2)) % m; // operacao para saber a posicao do objeto na tabela

	return resultado; // retornar o valor de da operacao acima
}

int hash_insert(dado t[], int m, int k) // adiciona novos elementos a tabela
{
	int i = 0;
	do
	{
		int j = dhash(k, m, i);
		if (t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
			i = i + 1;
	}
	while (i != m);
	return -1;
}

int hash_search(dado t[], int m, int k)
{
	int i, j;
	i = 0;
	do
	{
		j = dhash(k, m, i);
		if( t[j].k == k)
			return j;
		else
			i = i + 1;
	}
	while (t[j].status != 0 && i < m);
	return -1;
}

int hash_remove(dado t[], int m, int k)
{
	int j;
	j = hash_search(t, m, k);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0; // consegui remover
	}
	else
		return -1; // k nao esta na tabela
}

int main()
{
	int tamanho, i, k, opcao, x; // variaveis para a tabela hash como tamanho, contador e chave
	char info[50];
	cin >> tamanho;	 // cin para inserir o tamanho da tabela hash
	dado tabela_hash[tamanho]; // criando um vetor na struct do tamanho da variavel 'tamanho'

	i = 0;
	while(i < tamanho) // while para deixar todos os valores do vetor em 0
	{
		tabela_hash[i].status = 0;
		i++;
	}

	while(opcao != 5)
	{
		cin >> opcao;
		if(opcao == 1)
		{
			for(i = 0 ; i < strlen(info) ; i++)
			{
				cin.getline(tabela_hash[i].info,50);
			}
			hash_insert(tabela_hash, tamanho, k);
		}
		else if(opcao == 2)
		{
			
			for(i = 0 ; i < strlen(info) ; i++)
			{
				cin.getline(tabela_hash[i].info,50);
			}
			if(hash_search(tabela_hash, tamanho, k) == -1)
				cout << info << " nao encontrado" << endl;
			else
				cout << info << " encontrado na posicao " << hash_search(tabela_hash, tamanho, k) << endl;
		}
		else if(opcao == 3)
		{
			for(i = 0 ; i < strlen(info) ; i++)
			{
				cin.getline(tabela_hash[i].info,50);
			}
			hash_remove(tabela_hash, tamanho, k);
		}
		else if(opcao == 4)
		{
			i = 0;
			while(i < tamanho) // mostrar a tabela hash
			{

				if (tabela_hash[i].status == 1)
					cout << tabela_hash[i].k << " ";

				else
					cout << "-1 ";

				i++;
			}
		}

	}

	return 0;
}