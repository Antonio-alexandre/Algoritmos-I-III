#include <iostream>
using namespace std;

float ideal(float h, char sex)
{
	float pesoideal;
	switch(sex)
	{
		case 'M':
			pesoideal = 72.7 * h - 58;
			break;
		case 'F':
			pesoideal = 62.1 * h - 44.7;
			break;
	}
	
	return pesoideal;
}

int main()
{
	float altura;
	char sex;
	float pideal;
	
	cin >> altura >> sex;
	
	pideal = ideal(altura,sex);
	
	cout << "Peso ideal = " << pideal << " kg" << endl;
	
	return 0;
}