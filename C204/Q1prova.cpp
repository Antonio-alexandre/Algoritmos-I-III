#include <iostream>
#include <cmath>

using namespace std;

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int N;
    cin >> N;

    int x1, y1, x2, y2;
    cin >> x1 >> y1; // Lê o primeiro ponto

    double totalLength = 0.0;

    for (int i = 1; i < N; i++) {
        cin >> x2 >> y2; // Lê o próximo ponto
        totalLength += calculateDistance(x1, y1, x2, y2); // Calcula a distância e adiciona ao comprimento total
        x1 = x2;
        y1 = y2;
    }

    // Formata a saída para 3 casas decimais
    cout << fixed;
    cout.precision(3);
    cout << "Race Length: " << totalLength << " m" << endl;
    
    return 0;
}