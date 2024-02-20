#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> fila; //"ponteiro" para a lista gerada
	int x; //var aux para leitura dos dados
	int i; //contador
	
	for(i = 0; i < 3; i++)
	{
		cin >> x;
		fila.push_back(x); //insere x no final da lista
	}
	
	while(!fila.empty())
	{
		
		cout << *fila.begin() << endl; //mostra o primeiro elemento da lista
		fila.pop_front(); //remove o primeiro elemento da lista
	}
	
	return 0;
}