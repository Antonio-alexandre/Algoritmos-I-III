#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N, cod, quant, quantf = 0, i;
	float custo = 0, vendas = 0, result;

	cin >> N;

	for(i = 0; i < N; i++)
	{
		cin >> cod >> quant;

		quantf += quant;

		switch(cod)
		{
		case 1:
			custo += quant * 20.00;
			vendas += quant * 35.00;
			break;
		case 2:
			custo += quant * 30.00;
			vendas += quant * 50.00;
			break;
		case 3:
			custo += quant * 25.00;
			vendas += quant * 40.00;
			break;
		case 4:
			custo += quant * 50.00;
			vendas += quant * 70.00;
			break;
		case 5:
			custo += quant * 45.00;
			vendas += quant * 60.00;
		}
	}

	custo = custo + 300;

	cout << "Foram vendidos " << quantf << " produtos" << endl;
	cout << "Vendas: R$" << vendas << endl;
	cout << "Custo: R$" << custo << endl;
	if(custo > vendas)
	{
		result = custo - vendas;
		cout << "Prejuizo de R$" << fixed << setprecision(2) << result << endl;
	}
	else if(vendas > custo)
	{
		result = vendas - custo;
		cout << "Lucro de R$" << fixed << setprecision(2) << result << endl;
	}
	else
		cout << "Nao houve lucro nem prejuizo" << endl;

	return 0;
}
