#include <iostream>
using namespace std;

struct ponto {
    int x;
    int y;
};

int lado(ponto a, ponto b, ponto p) {
    double produto_vetorial = (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y);
    
    if (produto_vetorial > 0) {
        return 1; // p está à esquerda de ab
    } else if (produto_vetorial < 0) {
        return -1; // p está à direita de ab
    } else {
        return 0; // p está alinhado com ab
    }
}

int main() {
    ponto a;
    ponto b;
    ponto p;
    int resultado;
    
	cout << "Digite o valor das coordenadas de p: " << endl;
	cin >> p.x >> p.y;
	
	cout << "Digite o valor das coordenadas de a: " << endl;
	cin >> a.x >> a.y;

	cout << "Digite o valor das coordenadas de b " << endl;
	cin >> b.x >> b.y;
	
    
    if (resultado == 1) {
        cout << "p esta a esquerda de ab" << endl;
    } else if (resultado == -1) {
        cout << "p esta a direita de ab" << endl;
    } else {
        cout << "p esta alinhado com ab" << endl;
    }
    
    return 0;
}