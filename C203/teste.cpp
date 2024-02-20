#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float media;
    int num, cont = 0, soma = 0;
    cin >> num;

    while(num != 0)
    {
        soma += num;
        cont++;
        cin >> num;
    }
	
	if(cont != 0) { // Evita divisao por zero
    	media = (float) soma / cont;
    	cout << "A media dos numeros digitados eh: " << media << endl;
	} else {
    	cout << "Nenhum numero foi digitado." << endl;
	}
	
    return 0;
}