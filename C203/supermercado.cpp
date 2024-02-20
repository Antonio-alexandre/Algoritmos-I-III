#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> estoque;
	list<int> venda;
	int N, cod, i, operacao;
	
	cin >> N;
	
	for(i = 0; i < N; i++)
	{
		cin >> operacao;
		
		switch(operacao)
		{
			case 1:
				cin >> cod;
				estoque.push_back(cod);
				break;
			case 2:
				if(!estoque.empty())
				{
					cod = estoque.front();
					estoque.pop_front();
					venda.push_front(cod);
				}
				break;
		}
	}
	
	cout << "Estoque: "; //Imprime os produtos no estoque
	for(list<int>::iterator p = estoque.begin(); p != estoque.end(); p++)
	{
		cout << *p << endl;
	}
	
	cout << "Venda: ";
	for(list<int>::iterator p = venda.begin(); p != venda.end(); p++)
	{
		cout << *p << " " << endl;
	}
	
	
	while(!estoque.empty())
		estoque.pop_front();
	
	while(!venda.empty())
		venda.pop_front();
	
	return 0;
}