#include <iostream>
#include <iomanip>
using namespace std;


int seq(int vetor[], int cont, int x) //Funcao para a pesquisa sequencial
{
    bool encontrou = false;
    int i = 0;
    
    while(encontrou == false && i < cont)
        encontrou = vetor[i++] == x;
        
    if(encontrou)
        return(i - 1);
    else
        return -1;
}

int main()
{
    int m, cont = 0; //Inicializei o contador como 0
    int n; 
    int vetor[100];

    while(vetor[cont] != -1) //While para encerrar a entrada de dados quando digitado -1
	{
		cin >> vetor[cont];
		if(vetor[cont] != -1)
			cont++;
	}
	
    cin >> n;
    
    if(seq(vetor, cont, n) == -1) //Verificacao se o valor digitado foi encontrado no vetor
    {
        cout << n << " nao encontrado" << endl;
    }
    else
    {
        cout << fixed << setprecision(1)<< n << " encontrado na posicao " << seq(vetor, cont, n) << endl;
    }
    
    return 0;
}