#include <iostream>
using namespace std;

void converte(int anos, int meses, int dias, int &totalDias)
{
	totalDias = (anos * 365) + (meses * 30) + dias;
}

int main()
{
	int totalDias;
	int d, a, m;
	
	cin >> a >> m >> d;
	
	converte(a, m, d, totalDias);
	
	cout << totalDias << endl;
	
	return 0;
}