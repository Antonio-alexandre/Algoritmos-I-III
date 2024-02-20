#include <iostream>

using namespace std;

struct dado //Declaracao da struct para armazenar os numeros
{
    int num[50];
};

int main()
{
	dado *v; //Ponteiro para a struct
	int N, maior, i;
	
	v = new dado; //Alocacao de memoria
	
	cin >> N; //Quantidade de numeros a serem digitadosA
	
	for(i = 0; i < N; i++) //Entrada das variaveis na struct usando ponteiro
		cin >> v->num[i];
	
	for(i = 0; i < N; i++) //Verifica qual o maior numero
	{
		if(v->num[i] > v->num[i-1])
			maior = v->num[i];
	}
	
	cout << maior << endl; //Exibe o maior numero
		
	return 0;
}