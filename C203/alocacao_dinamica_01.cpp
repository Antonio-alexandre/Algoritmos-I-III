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
    int i, soma;
    
    v = new dado; //Alocando memoria
	    
    for(i = 0; i < 4; i++) //Entrada para armazenar os valores na struct utilizando o ponteiro
	{
		cin >> v->nota[i];
		soma+= v->nota[i];
	} 
	    
	v->media = (float)soma/4; //Calculo da media e atribuicao na varia
	     
    cout << v->media << fixed << setprecision(2) << endl; //Saida do valor da media
	    
    delete v; //Liberando a memoria alocada
	    
    return 0;
}