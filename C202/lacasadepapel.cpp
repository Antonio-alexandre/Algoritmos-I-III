#include <iostream>
using namespace std;

int main()
{
    //Declaração das variáveis
	int N, i, gostou = 0, ngostou = 0;
	int votos[10];

    //Entrada da quantidade de pessoas
	cin >> N;

	if(N > 0 && N < 1000)
	{
	    //Entrada dos votos
		for(i = 0; i < N; i++)
			cin >> votos[i];

		for(i = 0; i < N; i++)
		{
		    //Condição que acrescenta o contador de pessoas que gostaram
			if(votos[i] == 1)
				gostou++;

            //Condição que acrescenta o contador de pessoas que não gostaram
			if(votos[i] == -1)
				ngostou++;
		}
	}

	//Condições que verificam e exibem o resultado da votação
	if(gostou == ngostou)
		cout << "Deu empate" << endl;
	else if(gostou > ngostou)
		cout << "A maioria gostou" << endl;
	else
		cout << "A maioria nao gostou" << endl;

	return 0;
}
