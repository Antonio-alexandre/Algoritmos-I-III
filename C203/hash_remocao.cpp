#include <iostream>
using namespace std;

struct dado {
    int k;
    int status; // 0 = vazio, 1 = ocupado, -1 = exclu�do
};

int hashsondagem(int k, int i, int m)
{
    int sondagemlinear, aux;
    aux = k % m;
    if(aux < 0)
        aux += m;
    sondagemlinear = (aux + i) % m;
    return sondagemlinear; //Fun��o hashing simples (hash auxiliar + sondagem linear)
}

int hash_search(dado t[], int m, int k) //Verifica se o valor digitado est� na tabela, e caso n�o esteja, retorna -1
{
    int i = 0;
    do {
        int j = hashsondagem(k, i, m);
        if (t[j].status == 0) 
            return -1; 
        if (t[j].k == k && t[j].status == 1) 
            return j;
        i++;
    } while (i < m); 
    return -1;
}

int hash_insert(dado t[], int m, int k) {
    int i = 0;
    do { //Algoritmo de inser��o na tabela hashing
        int j = hashsondagem(k, i, m);
        if (t[j].status != 1) {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
		i++;
    } while (i < m);
    return -1;
}

int hash_remove(dado t[], int m, int k)
{
	int j = hash_search(t, m, k);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0; //Executa a remo��o e libera o espa�o
	}
	else
		return -1; //k n�o est� na tabela
}

int main()
{
	int m, k, i;
    cin >> m;
    dado tab[m];
    for (i = 0; i < m; i++) //Inicializa a tabela com as posi��es que n�o forem digitadas, vazias
    {
        tab[i].k = -1;
        tab[i].status = 0;
    }
    cin >> k;
    while (k != 0) //Insere os n�meros digitados na tabela (chamando a fun��o hash_insert) quando 0 n�o for digitado
    {
        hash_insert(tab, m, k);
        cin >> k;
    }
    cin >> k;
    hash_remove(tab, m, k);
    
    for(i = 0; i < m; i++) //Algoritmo para exibir a tabela (assim como no hash_insert)
	{
		cout << tab[i].k << " ";
	}
	cout << endl;
		
	return 0;
}