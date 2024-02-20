#include <iostream>
#include <string>
using namespace std;

// definir os dados das pedras
struct PedraPreciosa {
    string nome;
    double volume;
    double peso;
    double preco;
};

// definir uma matriz para memorizacao
double solucao[6][401];

// funcao para calcular o valor maximo usando programacao dinamica
double valorMaximo(PedraPreciosa pedras[], int n, double volumeMaximo, double pesoMaximo) {
    // caso base: se nao ha pedras ou o carrinho esta cheio/pesado demais, o valor e zero.
    if (n == 0 || volumeMaximo <= 0 || pesoMaximo <= 0) {
        return 0;
    }

    // se o resultado ja foi calculado antes retorne-o diretamente
    if (solucao[n][int(pesoMaximo)] != -1) {
        return solucao[n][int(pesoMaximo)];
    }

    // se a pedra atual for muito grande ou pesada para o carrinho, va para a proxima.
    if (pedras[n - 1].volume > volumeMaximo || pedras[n - 1].peso > pesoMaximo) {
        solucao[n][int(pesoMaximo)] = valorMaximo(pedras, n - 1, volumeMaximo, pesoMaximo);
    } else {
        // calcule o valor incluindo e excluindo a pedra atual
        double incluir = pedras[n - 1].preco + valorMaximo(pedras, n - 1, volumeMaximo - pedras[n - 1].volume, pesoMaximo - pedras[n - 1].peso);
        double excluir = valorMaximo(pedras, n - 1, volumeMaximo, pesoMaximo);

        // retorne o valor maximo entre incluir e excluir
        solucao[n][int(pesoMaximo)] = max(incluir, excluir);
    }

    return solucao[n][int(pesoMaximo)];
}

int main() {
    // definir o numero de pedras e os criterios do carrinho
    int n = 5;
    double volumeMaximo = 1.0;
    double pesoMaximo = 400.0;

    // inicializar as informacoes das pedras
    PedraPreciosa pedras[] = {
        {"Diamante", 0.455, 263, 500},
        {"Esmeralda", 0.521, 127, 410},
        {"Topazio", 0.857, 254, 320},
        {"Rubi", 0.065, 134, 315},
        {"Jade", 0.012, 111, 280}
    };

    // inicializar a matriz de memorizacao com -1
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= int(pesoMaximo); j++) {
            solucao[i][j] = -1;
        }
    }

    // calcular o valor maximo que pode ser obtido
    double valorTotal = valorMaximo(pedras, n, volumeMaximo, pesoMaximo);

    cout << "Valor maximo de pedras: R$" << valorTotal << endl;

    return 0;
}