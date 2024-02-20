#include <iostream>
#include <iomanip>
using namespace std;

//Fun��o para a soma das notas e c�lculo da m�dia
float media(int notas[], int nAlunos)
{
	float m, s;
	int i;
	
	for(i = 0; i < nAlunos; i++)
		s = s + notas[i];
	
	m = s / nAlunos;
	
	return m;
}

int main()
{
	int nota[100];
	int N, i;
	float vMedia;
	
	cin >> N; //Entrada do n�mero de alunos
	
	if(N <= 0 || N > 100) //Verifica��o caso 0 < N <= 100
		cin >> N;
	else
	{
		for(i = 0; i < N; i++)
			cin >> nota[i];
	}
	
	//Chamada da fun��o e atribui��o na vari�vel vMedia
	vMedia = media(nota, N);
	
	cout << "Media da turma = " << fixed << setprecision(2) << vMedia << endl;
	
	return 0;
}