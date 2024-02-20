#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
	ifstream arqin;
	char nomearq[50]; //Nome do arquivo a ser lido
	int vetor[10]; //Armazena as notas
	int i; //Contador
	int N; //Quantidade de elementos lidos
	
	//Lendo nome do arquivo
	cin.getline(nomearq, 50);
	
	//Abrindo arquivo para leitura
	arqin.open(nomearq, ifstream :: in);
	
	//Lendo dados do arquivo e armazenando no vetor
	i = 0;
	while(!arqin.eof())
	{
		arqin >> vetor[i];
		i++;
	}
	
	N = i;
	
	//Mostrando conteudo do vetor
	for(i = 0; i < N; i++)
		cout << vetor[i] << endl;
	
	//Fechando arquivo
	arqin.close();
			   	
	return 0;
}