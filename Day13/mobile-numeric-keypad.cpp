#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> moves = {
    {0, 8},
    {1, 2, 4},
    {2, 1, 3, 5},
    {3, 2, 6},
    {4, 1, 5, 7},
    {5, 2, 4, 6, 8},
    {6, 3, 5, 9},
    {7, 4, 8},
    {8, 0, 5, 7, 9},
    {9, 6, 8}
};

int countSequences(int n) {
    if (n == 1) return 10;

    vector<vector<long long>> dp(n, vector<long long>(10, 0));

    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int key = 0; key < 10; ++key) {
            for (int move : moves[key]) {
                dp[i][key] += dp[i - 1][move];
            }
        }
    }

    long long totalCount = 0;
    for (int i = 0; i < 10; ++i) {
        totalCount += dp[n - 1][i];
    }

    return totalCount;
}

int main() {
    int n = 2;
    cout << "Number of unique sequences of length " << n << ": " << countSequences(n) << endl;
    return 0;
}
