#include <iostream>
#include <algorithm>

using namespace std;

// Define a struct to represent each ride
struct Ride {
    int duration;
    int rating;
};

int main() {
    int T, N;
    cin >> T >> N;

    Ride rides[N];

    for (int i = 0; i < N; i++) {
        cin >> rides[i].duration >> rides[i].rating;
    }

    // Create a 2D array to store the maximum rating for each time and ride combination
    int dp[N + 1][T + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (rides[i - 1].duration <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - rides[i - 1].duration] + rides[i - 1].rating);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][T] << endl;

    return 0;
}