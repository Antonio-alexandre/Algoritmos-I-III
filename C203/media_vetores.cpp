#include <iostream>
#include <iomanip>

using namespace std;

struct dado //Declaracao da struct para armazenar os numeros e a media
{
    int num[50];
    float media;
};

int main()
{
    dado *v; //Ponteiro para a struct
    int N, i, soma = 0;
    
    v = new dado; //Alocacao de memoria
    
    cin >> N; //Entrada da quantidade de numeros
    
    for(i = 0; i < N; i++) //Armazena os valores na struct utilizando o ponteiro
    {
        cin >> v->num[i];
        soma += v->num[i];
    }
    
    v->media = (float)soma/N; //Calculo da media e atribuicao na struct
    
    cout << v->media << fixed << setprecision(2) << endl; //Saida com duas casas
    
    delete v; //Libera memoria alocada
    
    return 0;
}