#include <iostream>
using namespace std;

//Declaração da struct para receber o nome, data de nascimento e o sexo do usuário
struct dados
{
	char nome[50];
	char nascimento[50];
	char sexo;
};


int main()
{
	//Variável para a struct
	dados pessoa;
	
	//Entrada dos dados da struct
	cin.getline(pessoa.nome, 50);
	cin.getline(pessoa.nascimento, 50);
	cin >> pessoa.sexo;
	cin.ignore();
	
	//Saída dos dados da struct
	cout << pessoa.nome << endl;
	cout << pessoa.nascimento << endl;
	cout << pessoa.sexo << endl;
	
	return 0;
}