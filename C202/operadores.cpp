#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    double x;
    double y;
    double r;

    cout << "Digite um número: ";
    cin >> x;
    cout << "Digite mais um número: ";
    cin >> y;
    
    r = sqrt(sin(x)/pow(1+y, 2));

    cout << "O resultado e: " << r;

    return 0;
}  