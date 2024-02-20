#include <iostream>

using namespace std;

int main()
{
	int *v = NULL;
	int tam; // tamanho desejado para o vetor
	int i; // contador
	
	cin >> tam;
	v = new int[tam]; // alocacao dinamica de memoria
	
	for(i = 0; i < tam; i++)
		v[i] = 2 * i;
	
	for(i = 0; i < tam; i++)
		cout << v[i] << endl;
	
	delete[] v;
	
	return 0;
}