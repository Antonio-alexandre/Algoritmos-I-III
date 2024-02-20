#include <iostream>
using namespace std;

int pot(int a, int n)
{
	if(n==0)
		return 1;
	else
		return a * pot(a, n - 1); //retorna o cálculo de a vezes a potencia desse mesmo valor, retirando 1 de n
}

int main()
{
	int a, n; //variaveis
	
	cin >> a >> n;
	
	cout << pot(a, n) << endl; //saida com o calculo da potencia
	
	return 0;
}