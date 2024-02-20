#include <iostream>
using namespace std;

struct dado {
    int k;
    int status; // 0 = vazio, 1 = ocupado, -1 = excluído
};

int hashsondagem(int k, int i, int m)
{
    int sondagemlinear, aux;
    aux = k % m;
    if(aux < 0)
        aux += m;
    sondagemlinear = (aux + i) % m;
    return sondagemlinear; //Função hashing simples (hash auxiliar + sondagem linear)
}

int hash_search(dado t[], int m, int k) //Verifica se o valor digitado está na tabela, e caso não esteja, retorna -1
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
    do { //Algoritmo de inserção na tabela hashing
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

int main() {
    int m, k;
    cin >> m;

    //Inicializa a tabela com todas as posições vazias
    dado t[m];
    for (int i = 0; i < m; i++) {
        t[i].status = 0;
    }

    //Inserção das chaves na tabela hashing
    do {
        cin >> k;
        if (k != 0) {
            hash_insert(t, m, k);
        }
    } while (k != 0);
    
	cin >> k;
	
    int posicao = hash_search(t, m, k); //Chama a função hash_search e exibe a saída referente ao resultado
    if(posicao == -1)
		cout << "Chave " << k << " nao encontrada" << endl;
	else
		cout << "Chave " << k << " encontrada na posicao " << posicao << endl;

    return 0;
}