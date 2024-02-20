#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista) //Funcao para o calculo da soma
{
	int soma = 0;
	list<int>::iterator p; //'ponteiro' para varrer a lista
	
	for(p = lista.begin(); p != lista.end(); p++) //Calculando a soma dos valores
		soma += *p;
	
	return soma;
}

int main()
{
	list<int> lista; //'ponteiro' para a lista
	int x; //Var para a leitura dos dados
	
	cin >> x; //Primeira leitura do valor de x
	
	while(x != 0) //Inserindo dados na tabela
	{
		lista.push_back(x);
		cin >> x; 
	}
	
	cout << soma(lista) << endl; //Chamando a funcao soma, e exibindo o resultado do calculo
	
	while(!lista.empty()) //Liberando memoria usada pela lista
		lista.pop_front();
	
	return 0;
}