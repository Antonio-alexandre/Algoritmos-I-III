#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float raiz(float x, float x0, float e) //Funcao para o cálculo da raiz
{
    float x1 =(x0 * x0) - x;
    float x2;

    if(abs(x1) <= e) //Calculo do primeiro caso
    {
        return x0;
    }
    else //Calculo para o caso contrario
    {
        x2 = (x0x0 + x)/(2x0);
		return raiz(x, x2, e);
    }
}

int main()
{
    float x, x0;
    float e;

    cin >> x >> x0 >> e;

    cout << raiz(x, x0, e) << fixed << setprecision(4) << endl; //Saida com 4 casas apos a virgula

    return 0;
}