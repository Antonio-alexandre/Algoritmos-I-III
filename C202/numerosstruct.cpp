#include <iostream>
using namespace std;

struct numeros{
	int num;
	int x;	
};

int main()
{
	numeros sorte;
	int i;
	int soma = 0;
	
	//Entrada da quantidade de numeros a serem digitados
	cin >> sorte.x;
	
	//Entrada do n�mero, e caso ele for par, acrescenta � vari�vel soma
	for(i = 0; i < sorte.x; i++)
	{
		cin >> sorte.num;
		
		if(sorte.num % 2 == 0)
			soma += sorte.num;
	}
	
	cout << soma << endl;
	
	return 0;
}
