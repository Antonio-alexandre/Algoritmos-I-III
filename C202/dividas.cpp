#include <iostream>
#include <iomanip>
using namespace std;

// Retorna a soma dos elementos do vetor d
float soma(float d[], int n)
{
	float s = 0; // Soma dos elementos de d
	int i; // Contador
	
	for(i = 0; i < n; i++)
		s = s + d[i];
	
	return s;
}

int main()
{
	float dividas[5];
	int nDevedores = 4;
	float total;
	
	dividas[0] = 10.0;
	dividas[1] = 15.0;
	dividas[2] = 5.0;
	dividas[3] = 40.0;	
	
	total = soma(dividas, nDevedores);
	
	cout << "Quantidade total emprestada: R$ " << fixed << setprecision(2) << total << endl;
	
	return 0;
}