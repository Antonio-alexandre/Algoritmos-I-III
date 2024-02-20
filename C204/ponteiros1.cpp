#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	
	// declaracao das variaveis e dos ponteiros
	int a, b;	 
	int *p, *q; 	
	int aux;			
	
	cout << "De um valor para a:" << endl;
	cin >> a;

	cout << "De um valor para b:" << endl;
	cin >> b;
	
	p = &a;
	q = &b;
	
	cout << "Trocando..." << endl;

	// troca das variaveis
	aux = *p;
	*p = *q;
	*q = aux;

	cout << "Agora a tem o valor:" << endl;
	cout << a << endl;

	cout << "E b tem o valor:" << endl;
	cout << b << endl;
	return 0;
}
