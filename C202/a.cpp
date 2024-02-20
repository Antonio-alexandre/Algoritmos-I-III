#include <iostream>
using namespace std;

int soma(int a, int b)
{
	int s1;
	s1 = a + b;
	
	return s1;
}

int main()
{
	int x, y;
	int s = 0;
	
	x = 2;
 	y = 3;
 	
 	s = soma(x,y);
 	
 	cout << "s = " << s << endl;
	
	 soma();
	
	return 0;
}
