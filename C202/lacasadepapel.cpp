#include <iostream>
using namespace std;

int main()
{
    //Declara��o das vari�veis
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
		    //Condi��o que acrescenta o contador de pessoas que gostaram
			if(votos[i] == 1)
				gostou++;

            //Condi��o que acrescenta o contador de pessoas que n�o gostaram
			if(votos[i] == -1)
				ngostou++;
		}
	}

	//Condi��es que verificam e exibem o resultado da vota��o
	if(gostou == ngostou)
		cout << "Deu empate" << endl;
	else if(gostou > ngostou)
		cout << "A maioria gostou" << endl;
	else
		cout << "A maioria nao gostou" << endl;

	return 0;
}
