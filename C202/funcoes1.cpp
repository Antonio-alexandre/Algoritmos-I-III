#include<iostream>
#include <cmath>
using namespace std;

//Fun��o para o c�lculo A
int calc_a(int x)
{
	int r1;
	
	r1 = 2 * pow(x, 2) + 3 * x - 1;
	
	return r1;
}

//Fun��o para o c�lculo b
int calc_b(int x)
{
	int r2;
	
	r2 = pow(x, 3);
	
	return r2;
}

//Fun��o para o c�lculo c
int calc_c(int y)
{
	int r3;
	
	r3 = pow(y, 3);
	
	return r3;
}

int main()
{
    int a,b,c,x,y;
    
    cin >> x >> y; //Declara��o das vari�veis
    
    //Declara��es e sa�das referentes a cada resultado
    a = calc_a(x);
    cout << a << endl;
    
    b = calc_b(x);
    cout << b << endl;
    
    c = calc_c(y);
    cout << c << endl;
    
    return 0;
}