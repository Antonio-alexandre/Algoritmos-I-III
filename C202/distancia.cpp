#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
    float x;
    float y;
};

int main()
{
	ponto a, b;
	float d;
	
	cout << fixed << setprecision(2);
	
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	
	d = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	
	cout << d << endl;
	
	return 0;
}