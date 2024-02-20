#include <iostream>
using namespace std;

struct dado {
    int k;
    int status; //0 = vazio; 1 = ocupado; -1 = excluido
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

int hash_insert(dado t[], int m, int k) {
    int i = 0;
    do {
        int j = hashsondagem(k, i, m);
        if (t[j].status != 1) {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else {
            i++;
        }
    } while (i != m);
    return -1;
}

int main() {
    int x, k, i;
    cin >> x;

    dado tabela[x];  //Até a linha 44: inicializa a tabela hash com as posições vazias
    for (i = 0; i < x; i++) {
        tabela[i].status = 0;
    }

    do {   //Inserção das chaves na tabela
        cin >> k;
        if (k != 0) {
            hash_insert(tabela, x, k);
        }
    } while (k != 0);

    for (i = 0; i < x; i++) {   //Imprime a tabela usando cout
        if (tabela[i].status == 1) {
            cout << tabela[i].k << " ";
        }
        else {
            cout << "-1 ";
        }
    }
    cout << endl;

    return 0;
} 
