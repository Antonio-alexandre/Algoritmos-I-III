#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	ofstream arqout;
	char nomearq[100]; //nome do arquivo de saída
	int idade = 18;
	
	strcpy(nomearq, "texto.txt");
	
	//Abrindo arquivo para escrita
	arqout.open(nomearq, ofstream :: out);
	
	arqout << "Meu nome: Antonio" << endl;
	
	arqout << idade << endl;
	
	//Fechando o arquivo
	arqout.close();
	
	return 0;
}