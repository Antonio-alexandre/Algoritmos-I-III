#include <iostream>
using namespace std;

int main()
{	
     int a;
     int b;
     cout << "De um valor para a: " << endl;
     cin >> a;
     cout << "De um valor para b: " << endl;
     cin >> b;
     
     int *pont1;
     int *pont2;
     int aux;
     pont1 = &a;
     pont2 = &b;
     aux = *pont1;
     *pont1 = *pont2;
     pont2 = &aux;
     cout << "Apos a troca: " << endl;
     cout << "Valor de a: " << *pont1 << endl;
     cout << "Valor de b: " << *pont2 << endl;
     
	return 0;
}