#include <iostream>
using namespace std;

int main()
{
	char mat[10][10]; //Declaração das variáveis
	int lin;
	int col;
	int l, c;
	int soma = 0;
	
	cin >> lin; //Entrada das variáveis
	cin >> col;
	
	for(l = 0; l < lin; l++) //For para leitura
	{
		for(c = 0; c < col; c++)
		{
			cin >> mat[l][c];
		}
	}
	
	for(c = 0; c < col; c++) //For para contar quantos '1' vai ter
	{
		for(l = 0; l < lin; l++)
		{
			soma = mat[l][c] + soma;
		}
	}
	
	if(soma > 4) //Se na matriz contar mais de 4 '1', exibe masculino
		cout << "MASCULINO" << endl;
	else //Se na matriz contar menos ou igual a 4, exibe feminino
		cout << "FEMININO" << endl;
	
	return 0;
}