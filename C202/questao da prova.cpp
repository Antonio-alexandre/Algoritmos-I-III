#include <iostream>
using namespace std;

int main()
{
	int cod, quant;
	double total;
	bool comprou
	char nome[25];

	do
	{
		cin >> cod >> quant;
		switch(cod)
		{
		case 1:
			total += 1.5 * quant;
			break;
		case 2:
			total += 3.5 * quant;
			break;
		case 3:
			total += 4.0 * quant;
			break;
		case 4:
			total += 2.5 * quant;
			break;
		case 5:
			total += 3.5 * quant;
			break;
		default:
			cout << "Codigo Invalido" << endl;
		}
	}
	while(cod != -1);

	if(total ==   0)
		cout << "Volte sempre :)" << endl;
	else
	{
		cin.getline(nome, 25);
		cout << "Valor a pagar: " << total << endl;
		cout << ":) Obrigado pelo pedido " << nome << endl;

	}

	return 0;
}
