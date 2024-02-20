#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char nome[25];
    int idade;
    double ind;
    
    cin >> idade;
    cin >> nome;
    
    ind = idade * (0.0238095238) - (idade - 3);
    
    cout << fixed << setprecision(4);
    cout << "Ind = " << ind << endl;
    
    return 0;
}