#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
	ifstream arqin;
	char nomearq[50]; //Nome do arquivo a ser lido
	char linha[100]; //Armazena os dados lidos do arquivo
	
	//Nome do arquivo a ser lido
	cin.getline(nomearq, 50);
	
	//Abrindo o arquivo para leitura
	arqin.open(nomearq, ifstream :: in);
	
	//Lendo e mostrando informações contidas no arquivo
	while(!arqin.eof())
	{
		arqin.getline(linha, 100);
		cout << linha << endl;
	}
	
	//Fechando o arquivo
	arqin.close();
		   	
	return 0;
}