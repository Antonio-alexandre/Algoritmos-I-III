#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int a, b;			// variavel para entrar com os numeros a serem trocados
	int *p, *q; 		// ponteiros
	int aux;			// variavel auxiliar
	
	cout << "De um valor para a:" << endl;
	cin >> a;

	cout << "De um valor para b:" << endl;
	cin >> b;

	cout << "Trocando..." << endl;


	p = &a;
	q = &b;

	aux = *p;
	*p = *q;
	*q = aux;

	cout << "Agora a tem o valor:" << endl;
	cout << a << endl;

	cout << "E b tem o valor:" << endl;
	cout << b << endl;
	return 0;
}