#include <iostream>
#include <cmath>
using namespace std;

int hash_aux(int k, int m) //Fun��o hash
{
	int resultado; //Vari�vel de suporte 
	
	resultado = k % m;
	if(resultado < 0) //Caso o resultado for negativo, acrescenta m
	{
		resultado += m;
	}
	
	return resultado;
}

int hash2(int k, int i, int m, int c1, int c2)
{
	int hlinha = hash_aux(k, m); //Chama a fun��o hash_aux para a variavel hlinha
	int result; //Outra vari�vel de suporte
	
	result = (hlinha + (c1 * i) + (c2 * (i * i))) % m; //Formula do hash quadratico
	
	return result; //Retorna o resultado para cada valor de i
}

int main()
{
	int k, m, c1, c2, i; 
	
	cin >> k >> m >> c1 >> c2; //Entrada das vari�veis
	
	for(i = 0; i < m; i++)
		cout << hash2(k, i, m, c1, c2) << endl; //For para chamar a fun��o para cada valor de i
		
	return 0;
}	