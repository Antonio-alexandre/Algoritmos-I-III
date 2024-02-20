#include <iostream>

 

using namespace std;

 

int n = 5;
int c = 10;
int valor[5] = {13,45,23,12,56};
int peso[5] = {2,4,5,3,1};
int solucao[5][10];

 

int mochila(int item, int capacidade){

	if(item >= n)
		return 0;

	if(solucao[item][capacidade] != -1)
		return solucao[item][capacidade];

	int resposta1 = 0;
	if(capacidade >= peso[item])
		resposta1 = mochila(item+1, capacidade - peso[item])+ valor[item];

	int resposta2 = mochila(item+1, capacidade);

	int resposta = max(resposta1, resposta2);
	solucao[item][capacidade] = resposta;
	return resposta;
}

 

int main()
{

 

	for(int i=0; i<n; i++)
		for(int j=0; j<c; j++)
			solucao[i][j] = -1;

 

	int resposta = mochila(0, c);	
	cout<<resposta;
	return 0;
}