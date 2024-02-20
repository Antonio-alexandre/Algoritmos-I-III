#include <iostream>
using namespace std;

int main()
{
	//Declaração das variáveis
	int N, i, maior, menor;
	int amigos[10];

	//Entrada do número de pessoas
	cin >> N;
	
	//Condição que verifica se o N está entre 0 e 1000
	if(N > 0 && N < 1000)
	{
		for(i = 0; i < N; i++)
			cin >> amigos[i];

		maior = amigos[0];
		menor = amigos[0];

		for(i = 0; i < N; i++)
		{
			//Condição para verificar qual o maior número de amigos
			if(amigos[i] > maior)
				maior = amigos[i];
			
			//Condição para verificar qual o menor número de amigos
			if(amigos[i] < menor )
				menor = amigos[i];
		}

		//Saídas referentes aos números de amigos
		cout << "Menor numero de amigos: " << menor << endl;
		cout << "Maior numero de amigos: " << maior << endl;
	}
}
