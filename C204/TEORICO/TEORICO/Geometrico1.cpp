#include<iostream>
using namespace std;

struct ponto {
	int x;
	int y;
};

int area_triangulo(ponto a, ponto b, ponto c){
	return 
	(a.x * b.y - a.y * b.x +
	a.y * c.x - a.x * c.y +
	b.x * c.y - b.y * c.x)/2;
}


int main(){

	ponto p1;
	p1.x = 1;
	p1.y = 2;
	
	ponto p2;
	p2.x = 4;
	p2.y = 4;
	
	ponto p3;
	p3.x = 4;
	p3.y = 1;
	
	ponto p;
	p.x = 3;
	p.y = 2;
	
	float tprincipal = area_triangulo(p1,p2,p3);
	
	float l1 = area_triangulo(p,p2,p3) / tprincipal;
	float l2 = area_triangulo(p1,p,p3) / tprincipal;
	float l3 = area_triangulo(p1,p2,p) / tprincipal;
	
	cout<<"l1: "<<l1<<endl;
	cout<<"l2: "<<l2<<endl;
	cout<<"l3: "<<l3<<endl;
	
	return 0;
}