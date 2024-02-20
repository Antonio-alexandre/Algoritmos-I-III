#include <iostream>
using namespace std;

struct dado{ //Struct para os dados inseridos
    int k;
    int status = 0;
};

int hash_aux(int k, int m) //hash_auxiliar a ser utilizado no hashing quadratico
{
    int h = k % m;
    
    if(h < 0){ //Quando o resultado for menor que 0, soma ao valor de m e retorna o resultado
        return h += m;
    }
    else
    	return h;
}

int hash1(int k, int i, int m, int c1, int c2) //Calculo do hash quadratico
{
    int hquad;
    return hquad = (hash_aux(k,m) + c1 * i + c2 * (i*i))%m;
}

int hash_insert(dado t[], int m, int k, int c1, int c2) //Funcao para inserir os dados na tabela
{
    int i = 0;
    do
    {
        int j = hash1(k, i, m, c1, c2);
        
        if (t[j].status != 1)
        {
            t[j].k = k;
            
            t[j].status = 1;
            
            return j;
        }
        else
            i = i + 1;
    } while (i != m);
    return -1;
}

int hash_search(dado t[], int m, int k, int c1, int c2) //Funcao para pesquisar os dados na tabela
{
    int i, j;
    
    i = 0;
    
    do
    {
        j = hash1(k, i, m, c1, c2);
        if (t[j].k == k)
        {
            return j;
        }
        else
            i = i + 1;
    }
    while (t[j].status != 0 && i < m);
    
    return -1;
}

int main(){
    int m, c1, c2, i, k, j; //Declaracao das variaveis
    
    cin >> m >> c1 >> c2;
    
    dado tab[m]; //Incializacao da tabela com todas a posicoes vazias
    
    for(i = 0; i < m; i++)
    {
        tab[i].status = 0;
    }

    do //Entrada e insercao dos dados na tabela
    {
        cin >> k;
        if (k != 0)
        {
            hash_insert(tab, m, k, c1, c2);
        }
    }
    while (k != 0);
    
    cin >> k;

    if(hash_search(tab, m, k, c1, c2) == -1){ //Chama a funcao pesquisa para verificar se a chave esta na tabela
        cout << "Chave " << k << " nao encontrada" << endl;
    }
    else{
        cout << "Chave " << k << " encontrada na posicao " << hash_search(tab, m, k, c1, c2) << endl;
    }

    return 0;
}