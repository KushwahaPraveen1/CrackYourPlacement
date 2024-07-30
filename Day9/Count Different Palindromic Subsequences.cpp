class Solution {
public:
    int countPalindromicSubsequences(string s) {
        long n = s.size();
        long dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i] == s[j]) {
                    int low = i + 1;
                    int high = j - 1;
                    while (low < j && s[low] != s[j]) {
                        low++;
                    }
                    while (high > i && s[high] != s[j]) {
                        high--;
                    }

                    if (low > high) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (low == high) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        dp[i][j] =
                            (dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1]);
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                if (dp[i][j] < 0)
                    dp[i][j] += 1000000007;

                dp[i][j] = dp[i][j] % 1000000007;
            }
        }
        return dp[0][n - 1]; // ans
    }
};