#include <iostream>
using namespace std;

int sinal(int n)
{
	int s1;
	
	if(n > 0)
		s1 = 1;
	else if(n < 0)
		s1 = -1;
	else
		s1 = 0;
	
	return s1;
}

int main()
{
	int num;   
	int s;
	
	cin >> num;
	
	s = sinal(num);
	
	if(s == 1)
		cout << "Positivo" << endl;
	
	else if(s == -1)
		cout << "Negativo" << endl;
	
	else 
		cout << "Zero" << endl;
	
	return 0;
}