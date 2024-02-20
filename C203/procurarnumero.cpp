#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x) //Funcao para procurar o numero na lista
{
    list<int>::iterator p;
    for(p = lista.begin(); p != lista.end(); p++)
    {
        if(*p == x)
            return true;
    }
    return false;
}

int main()
{
    list<int> lista; //Declaracao da lista
    int n, p;  //Variaveis para os numeros da lista

    cin >> x; //Insere numeros enquanto 0 nao for digitado
    while(x != 0)
    {
        lista.push_back(x);
        cin >> x;
    }
    cin >> p; //Numero que ira procurar

    if(encontrar(lista, y)) //Chama a funcao
    {
        cout << "Encontrado" << endl;
    }
    else
    {
        cout << "Nao encontrado" << endl;
    }


    //liberando memoria
    while(!lista.empty())
        lista.pop_front();


    return 0;
}