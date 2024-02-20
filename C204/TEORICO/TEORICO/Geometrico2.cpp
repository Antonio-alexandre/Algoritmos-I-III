#include <iostream>
using namespace std;

struct ponto
{
	float x;
	float y; 	
};
typedef ponto vetor;

vetor cria_vetor(ponto A,ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A,vetor B)
{
	float v;
	v = A.x*B.y - A.y*B.x;
	return v;
}

/*
Posicao de P em relacao ao segmento AB
1 -> esquerda
-1 -> direita
0 -> colinear
*/
int lado(ponto A,ponto B, ponto P)
{
	vetor AB;
	vetor AP;
	float vet;
	AB = cria_vetor(A,B);
	AP = cria_vetor(A,P);
	vet = vetorial(AB,AP);
	if(vet > 0)
		return 1;
	else if(vet < 0)
		return -1;
	else
		return 0;
}

int main()
{
	ponto A, B, P;
	cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> P.x >> P.y;
    
    cout << lado(A, B, P);
    
	return 0;
}