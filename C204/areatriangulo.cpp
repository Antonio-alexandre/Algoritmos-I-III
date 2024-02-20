#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

vetor cria_vetor(ponto a, ponto b) //funcao para criar um vetor entre dois pontos
{
	vetor AB;
	AB.x = b.x - a.x;
	AB.y = b.y - a.y;
	return AB;
}

float vetorial(vetor a, vetor b) //funcao para calcular o produto vetorial
{
	float vet;
	vet = a.x * b.y - a.y * b.x;
	return vet;
}


float area_triangulo(ponto a, ponto b, ponto c) //funcao para calcular a area do triangulo utilizando vetores
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(a, b);
	AC = cria_vetor(a, c);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

int main()
{
	int n, i;
	ponto a, b, c;
	float areat;

	cin >> n;
	
	cout << fixed << setprecision(2);

	for(i = 0; i < n; i++) //funcao de repeticao para entrar com os conjuntos de tres pontos e calcular a area do triangulo
	{
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> c.x >> c.y;

		areat = area_triangulo(a, b, c);
		
		if(areat == 0)
			cout << "Nao formam triangulo" << endl;
		else
			cout << areat << endl;
	}

	return 0;
}