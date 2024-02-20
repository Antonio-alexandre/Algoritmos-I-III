#include <iostream>

using namespace std;

int dp[201][101];

int maxTempoEntrega(int Q, int pedidos[][2], int N) {
    for (int i = 0; i <= Q; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= Q; j++) {
            dp[j][i] = dp[j][i - 1];
            if (j >= pedidos[i - 1][1]) {
                dp[j][i] = max(dp[j][i], dp[j - pedidos[i - 1][1]][i - 1] + pedidos[i - 1][0]);
            }
        }
    }

    return dp[Q][N];
}

int main() {
    int Q, N;
    cin >> Q >> N;
    int pedidos[100][2];

    for (int i = 0; i < N; i++) {
        cin >> pedidos[i][0] >> pedidos[i][1];  // cin >> D >> X;
    }

    int resultado = maxTempoEntrega(Q, pedidos, N);
    cout << "Tempo: " << resultado << " min" << endl;

    return 0;
}