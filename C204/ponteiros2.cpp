#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int i = 0; 			
	int *p; 	
	int v[50];		
	int a, aux = 0;		
	
	p = v;
	
	cin >> a;

	while(a >= 0)
	{
		*p = a;
		p++;
		i++;
		cin >> a;
		aux = i;
	}

	p = v;
	
	for(i = 0; i < aux; i++) // for para exibir o vetor
	{
		cout << *p << ", ";
		p++;
	}

	return 0;
}