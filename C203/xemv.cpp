#include <iostream>
using namespace std;

int main()
{
	int v[] = {2,1,4,3};
	int x, i;
	int verificar = 0, posicao;
	
	cin >> x;
	
	for(i = 0; i < 4; i++)
	{
		if(v[i] == x)
		{
			verificar = 1;
			posicao = i;
		}
	}
	
	if(verificar == 1)
		cout << "X esta em V na posicao [" << posicao << "]" << endl;
	else
		cout << "X nao esta em V" << endl;
	
	return 0;
}