#include <iostream>

using namespace std;

int main()
{
	int a;
	int *b; //b e um ponteiro para int
	
	a = 2;
	b = &a;
	
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "b = " << b << endl;
	
	return 0;
}