#include <iostream>
using namespace std;

void quickSort(int vetor[], int tamanho, int i, int j)
{
	int trab,esq,dir,pivo, conti;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir)/2.0)];
	do
	{
		while (vetor[esq] < pivo)
			esq++;
		while (vetor[dir] > pivo)
			dir--;
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	} while (esq <= dir);
	
	if (dir-i >= 0)
		quickSort(vetor,tamanho,i,dir);
	if (j-esq >= 0)
		quickSort(vetor,tamanho,esq,j);
	
	for(conti = 0; conti < tamanho; conti++)
		cout << vetor[conti];
}

int main()
{
	int vetor[50], num;
	int i = 0;
	int j = 0;
	int tamanho;
	
	while(num =! -1)
	{
		vetor[j] = num;
		cin >> num;
		j++	
	}
	
	
	return 0;
}