#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v; //Vertice de destino
	int p; //Peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux;
    aux.v = v;
    aux.p = p;
    adj[u].push_back(aux);
    if(orientado == 0) //Se for nao orientado
    {
        aux.v = u;
        adj[v].push_back(aux);
    }
}

int main()
{
	list<no> adj[50]; //Lista de adjacencia
	list<no>::iterator q; //'ponteiro' para a lista
	int u, v; //Origem e destino da aresta
	int peso; //Peso da aresta
	no aux; //Variavel auxiliar para inserir os dados em adj
	int orient = 0; //0: Nao Orientado | 1: Orientado
	int i; //Contador
	int N; //Numero de vertices
	
	cin >> N >> orient;
	
	cin >> u >> v >> peso;
	
	while(peso != -1 && v != -1 && u != -1)
	{
		cin >> u >> v >> peso;
		cria_aresta(adj, u, v, peso, orient);
	}
	
	for(i = 0; i < N; i++)
	{
		for(q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << q->v << q->p << endl;
	}
	
	return 0;
}