#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//Declaração da struct
struct alunos
{
	int matricula[20];
	string nome[20];
	float nota[20], media;	
};

int main()
{
	alunos aluno;
	int i = 0, j, x = 0, pos, n, contador1 = 0, contador2 = 0;
	float menornota = 0, soma = 0;
	
	cin >> n;
	cin >> j;
	
	//Entrada das informações a serem inseridas na struct
	for(i = 0; i < n; i++)
	{
		cin.ignore();
		
		getline(cin, aluno.nome[i]);
		
		cin >> aluno.matricula[i] >> aluno.nota[i];
		
		contador1++;
	}
	
	//For para acrescentar a variável soma
	for(i = 0; i < n; i++)
		soma += aluno.nota[i];
	
	//Cálculo da media
	aluno.media = soma/contador1;
	
	//Declara a menornota como a nota na posição 0 do vetor
	if(i == 0)
	{
		menornota = aluno.nota[i];
		pos = x;
	}
	
	//For para a verificação da menor nota
	for(i = 0; i < n; i++)
	{
		if(aluno.nota[i] > menornota)
		{
			menornota = aluno.nota[i];
			pos = x;
		}
	}
	
	//Contador de suporte para a posição j do vetor
	for(i = 1; i < j; i++)
	{
		contador2++;
	}  
	
	//Saídas das informações
	cout << fixed << setprecision(2) << "Media: " << aluno.media << endl;
	cout << aluno.nome[pos] << endl;
	cout << fixed << setprecision(2) << aluno.nome[contador2] << " " << aluno.matricula[contador2] << " " << aluno.nota[contador2] << endl;

	
	return 0;
}