class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= k; ++i) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int j = 1; j <= n; ++j) {
            dp[1][j] = j;
        }

        for (int i = 2; i <= k; ++i) {
            for (int j = 2; j <= n; ++j) {
                int low = 1, high = j;
                while (low + 1 < high) {
                    int mid = low + (high - low) / 2;
                    if (dp[i - 1][mid - 1] < dp[i][j - mid]) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                dp[i][j] = 1 + min(max(dp[i - 1][low - 1], dp[i][j - low]),
                                   max(dp[i - 1][high - 1], dp[i][j - high]));
            }
        }

        return dp[k][n];
    }
};
