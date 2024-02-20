#include <iostream>
#include <cmath>
using namespace std;

//Função para calcular o delta
float calc_delta(float a, float b, float c)
{
	int rdelta;
	
	rdelta = pow(b, 2) - 4 * a * c;
	
	return rdelta;
}

int main()
{
	float a, b, c, delta;
	
	cin >> a >> b >> c; //Entrada dos coeficientes
	
	delta = calc_delta(a, b, c); //Atribuição da chamada da função à variável delta
	
	cout << "delta = " << delta << endl; //Saída do resultado do delta
	
	return 0;	
}