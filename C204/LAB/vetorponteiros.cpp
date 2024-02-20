#include <iostream>
using namespace std;

int main()
{
	int vetor[100];
	int n; // valor a ser adicionado ao vetor
	int tam = 0;
	int *ponteiro = vetor; // ponteiro para varrer o vetor

    bool controle = true;
    
    cout << "leitura: " << endl;
    
    while(controle){
		cin >> n;
		if(n >= 0){
			vetor[tam] = n;
			tam++; // incrementa tamanho do vetor
		}
		else {
			controle = false;
		}
	}
	
	cout << "valores dentro do vetor: " << endl;

	// mostrando o vetor por ponteiro
	for(int i = 0; i < tam; i++){
		cout << *ponteiro << endl;
        ponteiro++;
	}
	
	 // outra maneira de varrer o vetor com ponteiro
	 // for(int *i = numeros; i < (vetor+tam); i++)
     // cout << *i << endl;
		
	return 0;
}