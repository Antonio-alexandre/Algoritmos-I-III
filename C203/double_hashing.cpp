#include <iostream>
using namespace std;

int h1(int k, int m) //Função para o cálculo do h1 para cada valor de i
{
	int r; //Variável de apoio
	
	r = k % m;
	
	if(r < 0) //Adiciona m quando r é menor que 0
	{
		r += m;
	}
	
	return r;
}

int h2(int k, int m) //Função para o cálculo do h2 para cada valor de i
{
	int result; //Variável de apoio
	
	result = 1 + (k % (m - 1));
	
	if(result < 0) //Adiciona m quando o resultado é menor que 0
		result += m;
	
	return result;
}

int dhash(int k, int m, int i)
{
	int hum = h1(k, m); //Variável para receber o valor de h1
	int hdois = h2(k, m); //Variável para receber o valor de h2
	int resultado; //Variável de apoio
	
	resultado = (hum + i * hdois) % m; //Cálculo do double hashing
	
	return resultado; //Retorna o resultado do double hashing para cada valor de i
}

int main()
{
	int k, m, i;
	
	cin >> k >> m; //Entrada das variáveis
	
	for(i = 0; i < m; i++) //For para exibir o resultado do double hashing para cada valor de i
		cout << dhash(k, m, i) << endl;
	
	return 0;
}