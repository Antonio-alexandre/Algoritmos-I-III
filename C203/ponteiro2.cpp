#include <iostream>

using namespace std;

int main()
{
	int vetor[3];
	int *p;
	
	cout << "vetor = " << vetor << endl;
	
	vetor[0] = 2;
	vetor[1] = 6;
	vetor[2] = -1;
	
	p = vetor;
	
	cout << *p << endl;
	
	return 0;
}