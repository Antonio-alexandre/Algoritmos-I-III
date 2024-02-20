#include <iostream>
using namespace std;

int main()
{
	char mat[10][10]; //Declaração das variáveis
	int lin;
	int col;
	int l, c;
	
	cin >> lin; //Entrada das variáveis
	cin >> col;
	
	for(l = 0; l < lin; l++) //For para leitura
	{
		for(c = 0; c < col; c++)
		{
			cin >> mat[l][c];
		}
	}
	
	for(c = 0; c < col; c++) //Inverte as colunas com linhas para exibir a palavra codificada
	{
		for(l = 0; l < lin; l++)
		{
			cout << mat[l][c];
		}
	}
	
	return 0;
}