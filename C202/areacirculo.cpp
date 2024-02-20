#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int r;
    double A;

    cout << "Digite o valor do raio do círculo: ";
    cin >> r;
    
    A = 3.14159 * pow(r, 2);
    cout << fixed << setprecision(2);
    cout << "O valor da área do círculo é: " << A;

    return 0;
}