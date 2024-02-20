#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
	int i, j, k = 0, contador = 0, trab, limite; // contadores
	bool troca;
	
	troca = true;
	limite = tamanho - 1;
	
	while (troca)
	{
		troca = false;
		for (i = 0; i < limite; i++)
			if (vetor[i] > vetor[i + 1]) //Executa as trocas, exibe os valores do trab e acrescenta ao contador
			{
				trab = vetor[i];
				cout << "New trab: " << trab << endl;
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = trab;
				j = i;
				troca = true;
				contador++;
			}
		limite = j;
	}
	cout << "Contador:" << contador << endl; //Exibe quantas trocas foram feitas
}

int main()
{
	int vetor[50], n, i;

	cin >> n; //Entrada do tamanho do vetor
	
	for(i = 0; i < n; i++) //Entrada dos valores do vetor
	{
		cin >> vetor[i];

	}
	bubbleSort(vetor, n); //Chama a função para executar o bubbleSort

	return 0;
}