#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

typedef struct {
	int x;
	int y;	
} Ponto;

int distancia(Ponto p1, Ponto p2) //calcula a distancia entre dois pontos
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}


int main()
{
	Ponto a;
	Ponto b;
	Ponto c;
	Ponto d;
	
	//entrada dos pontos
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	
	//calcula a expessura, diametro e altura da torta usando a funcao de distancia
	cout << distancia(a, b) << endl;
	cout << distancia(c, d) << endl;
	cout << distancia(a, c) << endl;
	
	return 0;
}