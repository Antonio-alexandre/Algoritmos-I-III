#include <iostream> 
#include <climits> 
#include <algorithm> 
using namespace std;

int main()
{
	int custo[6][6]; //Matriz com limite de 6(maior quantidade de ilhas)
	int n; //Numero de ilhas
	int ilha_inicial;

	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
		{
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
	cin >> ilha_inicial;


	int vetor[100]; //Vetor com as cidades a serem permutadas
	int x; //Variavel auxiliar
	int menor_custo; //Viagem com menor custo
	int custo_caminho; //Custo do caminho a ser percorrido

	//Inserindo as ilhas a serem permutadas no vetor
	x = 0;
	for(int i = 0;i < n;i++)
		if(i != ilha_inicial)
		{
			vetor[x] = i;
			x++;
		}

	//Forca bruta
	menor_custo = INT_MAX; 
	cout << "Menor custo: ";
	do
	{
		custo_caminho = custo[ilha_inicial][vetor[0]]; 

		for(int i = 0;i < n-2;i++) 
			custo_caminho += custo[vetor[i]][vetor[i+1]];

		custo_caminho += custo[vetor[n-2]][ilha_inicial]; 

		menor_custo = min(menor_custo,custo_caminho);
	}while(next_permutation(vetor,vetor+(n-1))); 

	cout << menor_custo << endl;

	return 0;
}