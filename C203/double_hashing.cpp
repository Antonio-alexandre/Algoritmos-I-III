#include <iostream>
using namespace std;

int h1(int k, int m) //Fun��o para o c�lculo do h1 para cada valor de i
{
	int r; //Vari�vel de apoio
	
	r = k % m;
	
	if(r < 0) //Adiciona m quando r � menor que 0
	{
		r += m;
	}
	
	return r;
}

int h2(int k, int m) //Fun��o para o c�lculo do h2 para cada valor de i
{
	int result; //Vari�vel de apoio
	
	result = 1 + (k % (m - 1));
	
	if(result < 0) //Adiciona m quando o resultado � menor que 0
		result += m;
	
	return result;
}

int dhash(int k, int m, int i)
{
	int hum = h1(k, m); //Vari�vel para receber o valor de h1
	int hdois = h2(k, m); //Vari�vel para receber o valor de h2
	int resultado; //Vari�vel de apoio
	
	resultado = (hum + i * hdois) % m; //C�lculo do double hashing
	
	return resultado; //Retorna o resultado do double hashing para cada valor de i
}

int main()
{
	int k, m, i;
	
	cin >> k >> m; //Entrada das vari�veis
	
	for(i = 0; i < m; i++) //For para exibir o resultado do double hashing para cada valor de i
		cout << dhash(k, m, i) << endl;
	
	return 0;
}