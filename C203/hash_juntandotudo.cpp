#include <iostream>
using namespace std;

struct dado {
    int k;
    int status; // 0 = vazio, 1 = ocupado, -1 = excluido
};

int h1(int k, int m) //Funcao para o calculo do h1 para cada valor de i
{
	int r; //Variavel de apoio
	
	r = k % m;
	
	if(r < 0) //Adiciona m quando r e menor que 0
	{
		return r += m;
	}
	return r;
}

int h2(int k, int m) //Funcao para o calculo do h2 para cada valor de i
{
	int result; //Variavel de apoio
	
	result = 1 + (k % (m - 1));
	
	if(result < 0) //Adiciona m quando o resultado e menor que 0
		return result += m;        
	
	return result;
}

int dhash(int k, int m, int i)
{
	int hum = h1(k, m); //Variavel para receber o valor de h1
	int hdois = h2(k, m); //Variavel para receber o valor de h2
	
	return (hum + (i * hdois)) % m; //Retorna o resultado do double hashing para cada valor de i
}

int hash_search(dado t[], int m, int k) //Verifica se o valor digitado esta na tabela, e caso nao esteja, retorna -1
{
    int i = 0, j;
	do
	{
		j = dhash(k, m, i);
		if( t[j].k == k)
			return j;
		else
			i = i + 1;
	}
	while (t[j].status != 0 && i < m);
    return -1;
}

int hash_insert(dado t[], int m, int k) {
    int i = 0;
    do { //Algoritmo de insercao na tabela hashing
        int j = dhash(k, m, i);
        if (t[j].status != 1) {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
		i++;
    } while (i != m);
    return -1;
}

int hash_remove(dado t[], int m, int k)
{
	int j = hash_search(t, m, k);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0; //Executa a remocao e libera o espaco
	}
	else
		return -1; //k nao esta na tabela
}

int main()
{
    int m, k, i, cod, posicao;
    cin >> m;
    dado tab[m];
    for (int i = 0; i < m; i++) {
        tab[i].status = 0;
    }

    while(cod != 5)
    {
        switch(cod)
        {
            case 1:
				cin >> k;
				hash_insert(tab, m, k);
                break;
            case 2:
                cin >> k;
                posicao = hash_search(tab, m, k);
                if(posicao == -1)
					cout << "-1" << endl;
				else
					cout << posicao << endl;
                break;
            case 3:
                cin >> k;
                hash_remove(tab, m, k);
                break;
            case 4:
                for (i = 0; i < m; i++) {   //Imprime a tabela usando cout
                	if (tab[i].status == 1) {
                    	cout << tab[i].k << " ";
                	}
                	else 
					{
                    cout << "-1 ";
                	}
                }
                cout << endl;
                break;
        }
        cin >> cod;
    }

    return 0;
}
int h1(int k, int m) //Fun??o para o c?lculo do h1 para cada valor de i
{
	int r; //Vari?vel de apoio
	
	r = k % m;
	
	if(r < 0) //Adiciona m quando r ? menor que 0
	{
		r += m;
	}
	
	return r;
}

int h2(int k, int m) //Fun??o para o c?lculo do h2 para cada valor de i
{
	int result; //Vari?vel de apoio
	
	result = 1 + (k % (m - 1));
	
	if(result < 0) //Adiciona m quando o resultado ? menor que 0
		result += m;
	
	return result;
}

int dhash(int k, int m, int i)
{
	int hum = h1(k, m); //Vari?vel para receber o valor de h1
	int hdois = h2(k, m); //Vari?vel para receber o valor de h2
	int resultado; //Vari?vel de apoio
	
	resultado = (hum + i * hdois) % m; //C?lculo do double hashing
	
	return resultado; //Retorna o resultado do double hashing para cada valor de i
}

int hash_search(dado t[], int m, int k) //Verifica se o valor digitado est? na tabela, e caso n?o esteja, retorna -1
{
    int i = 0;
    do {
        int j = dhash(k, i, m);
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
    do { //Algoritmo de inser??o na tabela hashing
        int j = dhash(k, i, m);
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
		return 0; //Executa a remo??o e libera o espa?o
	}
	else
		return -1; //k n?o est? na tabela
}

int main()
{
    int m, k, i, cod, posicao, z, x;
    cin >> m;
    dado tab[m];
    for (int i = 0; i < m; i++) {
        t[i].status = 0;
    }

    while(cod != 5)
    {
        cin >> cod;
        switch(cod)
        {
            case 1:
                do {
                    cin >> k;
                    if (k != 0) {
                        hash_insert(tab, m, k);
                    }
                } while (k != 0);
                break;
            case 2:
                cin >> k;
                posicao = hash_search(tab, m, k);
                if(posicao == -1)
		            cout << "Chave " << k << " nao encontrada" << endl;
	            else
		            cout << "Chave " << k << " encontrada na posicao " << posicao << endl;
                break;
            case 3:
                cin >> k;
                hash_remove(tab, m, k);
                break;
            case 4:
                for(i = 0; i < m; i++)
                {
                    if(tab[i].status == 1)
                        cout << i << " " << tab[i].k << endl;
                }
                break;
        }
        cin >> cod;
    }

    return 0;
}