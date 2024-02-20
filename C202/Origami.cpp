#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	char letra;

	cout << "Digite um número: " << endl;
	cin >> num;

	num = num % 2;

	switch(num)
	{
	case 0:
		cout << "Escolha uma letra: " << endl;
		cout << " A | B | C | D " << endl;
		cout << "---------------*---------------" << endl;
		cin >> letra;
		switch(letra)
		{
		case 'A':
			cout << "Você é bonito(a)" << endl;
			break;
		case 'B':
			cout << "Você é inteligente" << endl;
			break;
		case 'C':
			cout << "Você é legal" << endl;
			break;
		case 'D':
			cout << "Você me deve um chocolate" << endl;
			break;
		default:
			cout << "Letra inválida" << endl;
			break;
		}
		break;
	case 1:
		cout << "Escolha uma letra: " << endl;
		cout << " E | F | G | H " << endl;
		cout << "---------------*---------------" << endl;
		cin >> letra;
		switch(letra)
		{
		case 'E':
			cout << "Você é educado(a)" << endl;
			break;
		case 'F':
			cout << "Você me deve uma bala" << endl;
			break;
		case 'G':
			cout << "Você me deve 10 reais" << endl;
			break;
		case 'H':
			cout << "Você é gente boa" << endl;
			break;
		default:
			cout << "Letra inválida" << endl;
			break;
		}
		break;
	}

	return 0;
}
