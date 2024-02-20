#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream arquivo;
	arquivo.open("inatel2.txt", ios :: out | ios :: in);
	
	if(!arquivo.is_open())
		arquivo.open("inatel2.txt", ios :: out | ios :: in | ios :: trunc);
		
	return 0;
}