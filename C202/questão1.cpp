#include <iostream>
using namespace std;

int main()
{
	int N, bissexto = 0, sec, i, ano;
	float porcent = 0, porcentum = 0;

	cout << "Digite a quantidade de anos: " << endl;
	cin >> N;

	for(i = 0; i < N; i++)
	{
		cin >> ano;

		if(ano % 100 == 0)
			sec = (ano / 100);
		else
			sec = (ano / 100) + 1;

		if(ano % 4 == 0 && ano % 100 == 0 && ano % 400 == 0)
		{
			cout << "O ano " << ano << " pertence ao seculo " << sec << " e eh bissexto" << endl;
			bissexto++;
		}
		else if(ano % 4 == 0 && ano % 100 != 0)
		{
			cout << "O ano " << ano << " pertence ao seculo " << sec << " e eh bissexto" << endl;
			bissexto++;
		}
		else
		{
			cout << "O ano " << ano << " pertence ao seculo " << sec << " e nao eh bissexto" << endl;
		}
	}
	cout << bissexto << endl;
	porcent = 1.0 * bissexto * (1.0 * (1 / N) * 100);
	cout << porcent << endl;

	cout << "Dos anos selecionados, " << porcent << "% eram bissextos" << endl;

	return 0;
}
