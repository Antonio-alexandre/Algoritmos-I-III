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
  
	//Saída da média da turma com 2 casas após a vírgula
	cout << "Media da turma = " << fixed << setprecision(2) << vMedia << endl;
	
	cout << "Alunos com nota abaixo da media: " << nAbaixo(nota, N, vMedia) << endl;
	cout << "Alunos com nota acima da media: " << nAcima(nota, N, vMedia) << endl;
	
	return 0;
}