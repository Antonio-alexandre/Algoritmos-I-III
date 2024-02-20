#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream arqin;
	char nomearq[50]; //Nome do arquivo a ser lido
	int vetor[25]; //Armazena as temperaturas
	int i = 0; //Contador
	int N; //Quantidade de valores lidos
	float soma = 0, media; //Soma dos elementos do arquivo
	
	//Entrada do nome do arquivo
	cin.getline(nomearq, 50);
	
	//Abre arquivo para leitura
	arqin.open(nomearq, ifstream :: in);
	
	//Lê os dados do arquivo e os armazena no vetor
	while(!arqin.eof())
	{
		arqin >> vetor[i];
		i++;
		soma += vetor[i];
	}
	
	N = i;
	
	media = soma / N;
	
	cout << "Temperatura media: " << fixed << setprecision(1) << media << " graus" << endl;
	
	//Fechando arquivo
	arqin.close();
			   	
	return 0;
}