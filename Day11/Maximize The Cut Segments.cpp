#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximizeCuts(int n, int x, int y, int z) {
    // Initialize dp array with -1
    vector<int> dp(n + 1, -1);
    dp[0] = 0; // Base case: 0 length requires 0 cuts

    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        if (i >= x && dp[i - x] != -1) {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i >= y && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i >= z && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    return dp[n] == -1 ? 0 : dp[n];
}

int main() {
    int n = 4, x = 2, y = 1, z = 1;
    cout << "Maximum number of segments: " << maximizeCuts(n, x, y, z) << endl;

    n = 5, x = 5, y = 3, z = 2;
    cout << "Maximum number of segments: " << maximizeCuts(n, x, y, z) << endl;

    return 0;
}
