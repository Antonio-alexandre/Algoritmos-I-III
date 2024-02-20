#include <iostream>
using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
	int i,j; // contadores
	int trab;
	bool troca;
	int limite;
	   
	troca = true;
	limite = tamanho-1;
	while (troca)
	{
		troca = false;
		for (i=0;i<limite;i++)
		if (vetor[i] > vetor[i+1])
		{
			trab = vetor[i];
			vetor[i] = vetor[i+1];
			vetor[i+1] = trab;
			j = i;
			troca = true;	 	
		}
		limite = j;
	}	
}

int main()
{
    int vetor[50];
	int tamanho;
	int i;

	cout << "Entre com o tamanho do vetor: ";
	cin >> tamanho;
	cout << "Entre com os elementos do vetor: ";
	
	for (i=0;i<tamanho;i++)
		cin >> vetor[i];
		bubbleSort(vetor,tamanho);


	return 0;
}