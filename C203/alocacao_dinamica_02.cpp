#include <iostream>
#include <iomanip>
	
using namespace std;
	
struct dado //Declaracao da struct para armazenar as notas e a media
{
	int nota[4];
	float media;
};

int main()
{
    dado *v; //Ponteiro para a struct
    int i, j, soma, somat, n, mediat;
 	
 	cin >> n;
    
    v = new dado[n]; //Alocando memoria
	 	    
	for(j = 0; j < n; j++)
	{
		for(i = 0; i < 4; i++) //Entrada para armazenar os valores na struct utilizando o ponteiro
		{
			cin >> v->nota[i];
			soma+= v->nota[i];
		}
		//Calcula a media para cada struct, e soma o valor calculado a variavel da somatotal
		v->media = soma/(4*n);
	}
	     
    cout << v->media << fixed << setprecision(2) << endl; //Saida do valor da media das medias
	    
    delete [] v; //Liberando a memoria alocada
	    
    return 0;
}