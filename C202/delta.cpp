#include <iostream>
#include <cmath>
using namespace std;

//Fun��o para calcular o delta
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
	
	delta = calc_delta(a, b, c); //Atribui��o da chamada da fun��o � vari�vel delta
	
	cout << "delta = " << delta << endl; //Sa�da do resultado do delta
	
	return 0;	
}