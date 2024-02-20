#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int N, i;
	float a, b, c, area = 0, p = 0, sqr = 0;
	
	cin >> N;

	for(i = 0; i < N; i++)
	{
		cin >> a >> b >> c;

		if(a > (b + c) || b > (a + c) || c > (a + b))
			cout << "Os lados nao formam um triangulo" << endl;
		else
		{
			p = (a + b + c) / 2;

			area = sqrt(sqr = p * (p - a) * (p - b) * (p - c));

			cout << "Area do triangulo: " << fixed << setprecision(2) << area << " unidades de area" << endl;
		}
	}

	return 0;
}
