#include <iostream>
#include<list>

using namespace std;

int main)
{
	list<int> pilha; //"ponteiro" para a lista ligada
	int x; //var aux para leitura dos dados
	
	cin >> x;
	pilha.push_front(x); //insere x no inicio da lista
	
	cin >> x;
	pilha.push_front(x) //insere x no inicio da lista
	
	while(!pilha.empty())
	{   
		cout << *pilha.begin() << endl; //mostra o primeiro elemento da lista
		pilha.pop_front(); //remove o primeiro elemento da lista		
	}
	   	
	return 0;
}