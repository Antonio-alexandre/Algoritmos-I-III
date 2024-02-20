#include <iostream>

using namespace std;

int soma(int x, int y, int *s1)
{
	*s1 = x + y;
}

int main()
{
	int a, b;
	int s = 0;
	
	cin >> a >> b;
	
	soma(a, b, &s);
	
	cout << "s = " << s << endl;
	
	return 0;
}