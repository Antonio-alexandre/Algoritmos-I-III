#include <iostream>
#include <climits>

using namespace std;

const int MAX_CITIES = 10;

int main() {
    int n;
    cin >> n;

    int dist[MAX_CITIES][MAX_CITIES];
    bool visited[MAX_CITIES] = {false};
    int path[MAX_CITIES];
    int totalDistance = 0;

    // Leitura das dist�ncias entre as cidades
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int currentCity = 0; // Come�a da cidade 0
    visited[currentCity] = true;
    path[0] = currentCity;
    
    // Encontra o vizinho mais pr�ximo em cada etapa
    for (int step = 1; step < n; step++) {
        int nearestCity = -1;
        int minDistance = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[currentCity][i] < minDistance) {
                nearestCity = i;
                minDistance = dist[currentCity][i];
            }
        }

        visited[nearestCity] = true;
        path[step] = nearestCity;
        totalDistance += minDistance;
        currentCity = nearestCity;
    }

    // Volta � cidade de origem
    totalDistance += dist[currentCity][0];

    // Impress�o da ordem das cidades visitadas
    for (int i = 0; i < n; i++) {
        cout << path[i] + 1 << " "; // Adiciona 1 para come�ar da cidade 1
    }
    cout << endl;

    // Impress�o da dist�ncia total
    cout << totalDistance << endl;

    return 0;
}