#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int num;
	char letra;

	cout << "Digite um n�mero: " << endl;
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
			cout << "Voc� � bonito(a)" << endl;
			break;
		case 'B':
			cout << "Voc� � inteligente" << endl;
			break;
		case 'C':
			cout << "Voc� � legal" << endl;
			break;
		case 'D':
			cout << "Voc� me deve um chocolate" << endl;
			break;
		default:
			cout << "Letra inv�lida" << endl;
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
			cout << "Voc� � educado(a)" << endl;
			break;
		case 'F':
			cout << "Voc� me deve uma bala" << endl;
			break;
		case 'G':
			cout << "Voc� me deve 10 reais" << endl;
			break;
		case 'H':
			cout << "Voc� � gente boa" << endl;
			break;
		default:
			cout << "Letra inv�lida" << endl;
			break;
		}
		break;
	}

	return 0;
}
