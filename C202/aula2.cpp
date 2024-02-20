#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Digite o primeiro numero: ";
    cin >> a;
    cout << "Digite o segundo numero: ";
    cin >> b;
    cout << "Digite o terceiro numero: ";
    cin >> c;
    if (a > b && a > c) {
        cout << "O maior numero e: " << a;
    } else if (b > a && b > c) {
        cout << "O maior numero e: " << b;
    } else {
        cout << "O maior numero e: " << c;
    }
    return 0;
}
