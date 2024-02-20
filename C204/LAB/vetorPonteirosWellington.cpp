#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int i; 			// contador
	int *p; 		// ponteiro
	int v[50];		// vetor
	int x, aux;		// variaveis auxiliares
	p = v;


	for(i = 0; i < 50; i++)
	{
		cin >> x;
		if(x >= 0)
		{
			*p = x;
			p++;
			aux = i;
		}
		else
		{
			break;
		}
	}

	p = v;
	for(i = 0; i <= aux; i++)
	{
		cout << *p << ", ";
		p++;
	}

	return 0;
}