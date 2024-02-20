#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho) //Função para a inserção direta dos dados
{
    int i, j, m; 
    int chave;
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] > chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
    for(int m = tamanho - 1; m >= 0; m--) // mostra o vetor ao contrario em ordem decrescente
    {
        cout << vetor[m] << endl;
    }
}

int main()
{
    int vet[100], i = 0, tamanho=0;

    while(vetor[i] != 0)
    {
        cin >> vetor[i];
        if(vetor[i] != 0)
        {
            i++;
            tamanho++;
        }
        else
        {
            i--;
            break;
        }
    }
    insercaoDireta(vet, tamanho);

    return 0;
}