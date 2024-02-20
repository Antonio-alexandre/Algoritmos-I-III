#include <iostream>

using namespace std;

struct dado //Declaracao da struct para armazenar os numeros
{
    int num[50];
};

int main()
{
	dado *v; //Ponteiro para a struct
	int N, i;
	
	v = new dado; //Alocacao de memoria
	
	cin >> N; //Entrada da quantidade de numeros
	
	for(i = 0; i < N; i++) //Entrada dos valores na struct usando ponteiro
		cin >> v->num[i];
	
	for(i = 0; i < N; i++) //Saida dos valores da struct
		cout << v->num[i] << endl;	
	
	return 0;
}
