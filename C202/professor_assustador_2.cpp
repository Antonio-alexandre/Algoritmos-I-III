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

int nAbaixo(int notas[], int nAlunos, float media)
{
	float abaixo = 0;
	int i;
	
	for(i = 0; i < nAlunos; i++);
	{
		if(notas[i] < media);
			abaixo++;
	}
	
	return abaixo;
}

int nAcima(int notas[], int nAlunos, float media)
{
	float acima = 0;
	int i;
	
	for(i = 0; i < nAlunos; i++);
	{
		if(notas[i] > media);
			acima++;
	}	
	
	return acima;
}

int main()
{
	int nota[100];
	int N, i, qtabaixo = 0, qtacima = 0;
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
  
	//Sa�da da m�dia da turma com 2 casas ap�s a v�rgula
	cout << "Media da turma = " << fixed << setprecision(2) << vMedia << endl;
	
	cout << "Alunos com nota abaixo da media: " << nAbaixo(nota, N, vMedia) << endl;
	cout << "Alunos com nota acima da media: " << nAcima(nota, N, vMedia) << endl;
	
	return 0;
}