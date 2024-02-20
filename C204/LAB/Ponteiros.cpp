#include <iostream>

using namespace std;

int main() {
    // Exemplo 1: Declarando e usando um ponteiro
    int numero = 42;
    int* ponteiro = &numero; // Declarando um ponteiro para um inteiro e atribuindo o endereço de 'numero'
    
    cout << "Exemplo 1:" << endl;
    cout << "Valor de numero: " << numero << endl;
    cout << "Endereço de numero: " << &numero << endl;
    cout << "Valor do ponteiro: " << *ponteiro << endl; // Usando o operador '*' para acessar o valor apontado

    // Exemplo 2: Modificando o valor através de um ponteiro
    *ponteiro = 99;
    
    cout << "Exemplo 2:" << endl;
    cout << "Novo valor de numero: " << numero << endl;
    cout << "Novo valor de ponteiro: " << *ponteiro << endl;

    // Exemplo 3: Ponteiro para arrays
    int tamanhaNumero = 5;
    int numeros[5] = {1, 2, 3, 4, 5};
    int* ponteiroArray = numeros; // O nome do array é implicitamente um ponteiro para o primeiro elemento

    cout << "Exemplo 3:" << endl;
    cout << "Primeiro elemento do array: " << *ponteiroArray << endl;

    // Exemplo 4: Avançando através de um array com ponteiro
    ponteiroArray++; // Avança o ponteiro para o próximo elemento
    cout << "Segundo elemento do array: " << *ponteiroArray << endl;

    //para varrer o vetor

    for(int *i = numeros; i < (numeros+tamanhaNumero); i++)
        cout << *i << endl;
    
    return 0;
}