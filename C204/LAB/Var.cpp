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
Posicao de C em relacao ao segmento AB
1 -> esquerda
-1 -> direita
0 -> colinear
*/
int sentido(ponto A,ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float vet;
	AB = cria_vetor(A,B);
	AC = cria_vetor(A,C);
	vet = vetorial(AB,AC);
	if(vet > 0)
		return 1;
	else if(vet < 0)
		return -1;
	else
		return 0;
}

int main()
{
	ponto A, B, C;
	cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    
    if(sentido(A, B, C) == -1){
		cout << "NAO GOL!" << endl;
	}else{
		cout << "GOL!" << endl;
	}
    
	return 0;
}