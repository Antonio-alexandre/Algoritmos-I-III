#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int subsequenteMaisComum(int vet1[], int m, int vet2[], int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (vet1[i - 1] == vet2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    int m, n;
    cin >> m;

    int vet1[m];
    for (int i = 0; i < m; i++) {
        cin >> vet1[i];
    }

    cin >> n;

    int vet2[n];
    for (int i = 0; i < n; i++) {
        cin >> vet2[i];
    }

    int resultado = subsequenteMaisComum(vet1, m, vet2, n);
    cout << resultado << endl;

    return 0;
}
