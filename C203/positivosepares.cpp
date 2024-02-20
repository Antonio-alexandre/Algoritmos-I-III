#include <iostream>

using namespace std;

struct dado //Struct para armazenar os valores
{
	int num[50];
};

int main()
{
	dado *v; //Ponteiro para a struct
	int N, i, cont = 0;
	
	v = new dado; //Alocacao de memoria
	
	cin >> N; //Entrada da quantidade de numeros
	
	for(i = 0; i < N; i++) //Entrada dos valores usando ponteiro
		cin >> v->num[i];
	
	for(i = 0; i < N; i++)
	{
		if(v->num[i] > 0 && v->num[i] % 2 == 0) //Verifica se os numeros sao pares e positivos
			cont++;
	}
	
	cout << cont << endl; //Exibe o valor do contador
	
	return 0;
}