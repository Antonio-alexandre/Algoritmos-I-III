#include <iostream>
using namespace std;

int pot(int a, int n)
{
	if(n == 0)
		return 1;
	else
	{
		return a * pot(a, n-1);
	}
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << pot(x,y) << endl;
	
	return 0;
}