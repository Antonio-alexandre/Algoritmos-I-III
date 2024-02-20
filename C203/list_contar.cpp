#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista) //Funcao para contar os elementos
{
	int contador = 0;
	list<int>::iterator p; //'ponteiro' para varrer a lista
	
	for(p = lista.begin(); p != lista.end(); p++) //Contando os valores
		if(*p != 0)
			contador++;
	
	return contador;
}

int main()
{
	list<int> lista; //'ponteiro' para a lista
	int x; //Var para a leitura dos dados
	
	while(x != 0) //Inserindo dados na lista
	{
		cin >> x; 
		lista.push_back(x);
	}
	
	cout << contar(lista) << endl; //Chamando a funcao contar, e exibindo a quantidade de elementos na lista
	
	while(!lista.empty()) //Liberando memoria usada pela lista
		lista.pop_front();
	
	return 0;
}