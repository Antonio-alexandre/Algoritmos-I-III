#include <iostream>
#include <iomanip>
	
using namespace std;
	
struct dado //Declaracao da struct para armazenar as notas e a media
{
	int num[4];
};

int main()
{
    dado *v; //Ponteiro para a struct
    int i, N;
    
    cin >> N;
    
    v = new dado; //Alocando memoria
	    
    for(i = 0; i < N; i++) //Entrada para armazenar os valores na struct utilizando o ponteiro
	{
		cin >> v->num[i];
	} 
	     
    for(i = 0; i < N; i++)
    	cout << v->num[i] << endl;
	    
    delete v; //Liberando a memoria alocada
	    
    return 0;
}