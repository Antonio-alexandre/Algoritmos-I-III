#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int x, y, z;
	cout << "Digite os valores de x e y (Separados por espa�o em branco)" << endl;
	cin >> x >> y;
	
	z = x + y;
	
	cout << "O resultado �: " << z;
	
	return 0;
}
