#include <iostream>
using namespace std;

int main()
{
	//Declara��o das vari�veis
	int N, i, maior, menor;
	int amigos[10];

	//Entrada do n�mero de pessoas
	cin >> N;
	
	//Condi��o que verifica se o N est� entre 0 e 1000
	if(N > 0 && N < 1000)
	{
		for(i = 0; i < N; i++)
			cin >> amigos[i];

		maior = amigos[0];
		menor = amigos[0];

		for(i = 0; i < N; i++)
		{
			//Condi��o para verificar qual o maior n�mero de amigos
			if(amigos[i] > maior)
				maior = amigos[i];
			
			//Condi��o para verificar qual o menor n�mero de amigos
			if(amigos[i] < menor )
				menor = amigos[i];
		}

		//Sa�das referentes aos n�meros de amigos
		cout << "Menor numero de amigos: " << menor << endl;
		cout << "Maior numero de amigos: " << maior << endl;
	}
}
