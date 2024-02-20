#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream arquivo;
	arquivo.open("inatel.txt", ios :: out | ios :: in);
	
	if(arquivo.is_open())
		cout << "Arquivo aberto" << endl;
	else
		cout << "Arquivo nao encontrado" << endl;
		
	return 0;
}