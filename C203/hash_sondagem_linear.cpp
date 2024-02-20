#include <iostream>

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

int hash1(int k, int i, int m) //Fun��o para a sondagem linear
{
	   int hlinha = hash_aux(k, m); //Vari�vel que recebe o valor do h'
	   int r;
	   
	   r = (hlinha + i) %m;
	   
	   return r; //Retorna o resultado para cada valor de i
}

int main()
{
	int i, k, m;
	
	cin >> k >> m;
	
	for(i = 0; i < m; i++) //Executa a sondagem linear para cada valor de i
	{
		cout << hash1(k, i, m) << endl;
	}
		
	return 0;
}