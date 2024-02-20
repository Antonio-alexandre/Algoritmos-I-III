#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
	ifstream arqin;
	char nomearq[50]; //Nome do arquivo a ser lido
	char texto[100]; //Armazena o texto lido do arquivo
	
	//Entrada do nome do arquivo
	cin.getline(nomearq, 50);
	
	//Abre o arquivo para leitura
	arqin.open(nomearq, ifstream :: in);
	
	//Enquanto n�o chega ao fim do arquivo, armazena os dados na vari�vel texto
	while(!arqin.eof())
	{
		arqin.getline(texto, 100);
		cout << texto << endl;
	}
	
	//Fechando o arquivo
	arqin.close();
		   	
	return 0;
}