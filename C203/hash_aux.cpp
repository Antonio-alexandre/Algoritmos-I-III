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

int main()
{
	int k, m;
	
	do //do-while para entrada de dados e verifica��o caso as duas vari�veis s�o negativas
	{
		cin >> k >> m;
		if(k != 0 && m != 0)
		{
			cout << hash_aux(k, m) << endl;
		}
	} while(k != 0 && m != 0);
	
	return 0;
}