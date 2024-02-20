#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int cod;
	double preco;
	char cliente[50];
	char cidade[50];
	int idade;
	double pag;

	cin >> cod >> preco;
	cin.ignore();
	cin.getline(cliente, 50);
	cin.getline(cidade, 50);
	cin >> idade;
	cin >> pag;

	switch(cod)
	{
	case 1:
		cout << "Queijo" << endl;
		break;
	case 2:
		cout << "Geleia" << endl;
		break;
	case 3:
		cout << "Doce" << endl;
		break;
	case 4:
		cout << "Refrigerante" << endl;
		break;
	case 5:
		cout << "Sorvete" << endl;
		break;
	case 6:
		cout << "Presunto Cru" << endl;
		break;
	case 7:
		cout << "Vinho" << endl;
		break;
	default:
		cout << "Codigo invalido" << endl;
	}
	cout << fixed << setprecision(2);
	cout << "Valor total: R$ " << preco << endl;

	if(pag < preco)
		cout << "Pagamento insuficiente" << endl;
	else
		cout << "Troco R$: " << pag - preco << endl;

	return 0;
}
