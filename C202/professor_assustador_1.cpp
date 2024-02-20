#include <iostream>
#include <iomanip>
using namespace std;

//Função para a soma das notas e cálculo da média
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
	
	cin >> N; //Entrada do número de alunos
	
	if(N <= 0 || N > 100) //Verificação caso 0 < N <= 100
		cin >> N;
	else
	{
		for(i = 0; i < N; i++)
			cin >> nota[i];
	}
	
	//Chamada da função e atribuição na variável vMedia
	vMedia = media(nota, N);
	
	cout << "Media da turma = " << fixed << setprecision(2) << vMedia << endl;
	
	return 0;
}