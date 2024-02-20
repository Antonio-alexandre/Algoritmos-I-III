#include <iostream>
using namespace std;

int main()
{
	int mat[10][10]; //Criando matriz com base no máximo
	int mat1[10][10]; //
	int mat2[10][10]; //
	int nLinhas; //Variável do número de linhas
	int nColunas; //Variável do número de colunas
	int l, c; //Contadores
	
	cin >> nLinhas; //Adicionando quantidade de linhas
	cin >> nColunas; //Adicionando quantidade de colunas
	
	for(l = 0; l < nLinhas; l++) //For para adicionar valores nas linhas
	{
		for(c = 0; c < nColunas; c++) //For para adicionar os valores nas colunas
		{
			cin >> mat[l][c]; //Cin para inserir os valores
		}
	}
	
	for(l =0; l < nLinhas; l++) //For para leitura dos valores da matriz1
	{
		for(c = 0; c < nColunas; c++) 
		{
			cin >> mat1[l][c];
		}
	}
	
	for(l =0; l < nLinhas; l++) //For para a soma das duas matrizes
	{
		for(c = 0; c < nColunas; c++) 
		{
			mat2[l][c] = mat[l][c] + mat1[l][c];
		}
	}
	
	for(l =0; l < nLinhas; l++) //For para exibir a matriz3
	{
		for(c = 0; c < nColunas; c++) 
		{
			cout << mat2[l][c] << " ";
		}
		cout << endl; //Executa um endl para descer a linha da matriz
	}
	
	
	return 0;
}