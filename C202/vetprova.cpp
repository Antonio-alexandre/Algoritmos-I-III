#include <iostream>
#include <string>
using namespace std;

int main()
{
	int vet[50];
	int i = 0, j, soma = 0;
	string opcao;
	
	cin >> vet[0];
	
	while(vet[i] != 0)
	{
		i++;
		cin >> vet[i];
	}
	
	cin.ignore();
	getline(cin, opcao);
	
	for(j = 0; j < i; j++)
	{
		if(opcao == "PAR" && vet[j] % 2 == 0)
			soma += vet[j];
		else if(opcao == "IMPAR" && vet[j] % 2 == 1)
			soma += vet[j];
	}
	
	cout << "soma = " << soma << endl;
	
	return 0;
}