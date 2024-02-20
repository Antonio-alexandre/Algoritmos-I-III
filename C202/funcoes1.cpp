#include<iostream>
#include <cmath>
using namespace std;

//Função para o cálculo A
int calc_a(int x)
{
	int r1;
	
	r1 = 2 * pow(x, 2) + 3 * x - 1;
	
	return r1;
}

//Função para o cálculo b
int calc_b(int x)
{
	int r2;
	
	r2 = pow(x, 3);
	
	return r2;
}

//Função para o cálculo c
int calc_c(int y)
{
	int r3;
	
	r3 = pow(y, 3);
	
	return r3;
}

int main()
{
    int a,b,c,x,y;
    
    cin >> x >> y; //Declaração das variáveis
    
    //Declarações e saídas referentes a cada resultado
    a = calc_a(x);
    cout << a << endl;
    
    b = calc_b(x);
    cout << b << endl;
    
    c = calc_c(y);
    cout << c << endl;
    
    return 0;
}