#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int minCostWordWrap(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i) {
        int length = 0;
        for (int j = i; j < n; ++j) {
            length += nums[j];
            if (length + (j - i) > k) break; 
               int extraSpaces = k - length - (j - i);
            int cost = (j == n - 1) ? 0 : extraSpaces * extraSpaces;
            dp[i] = min(dp[i], cost + dp[j + 1]);
        }
    }

    return dp[0];
}

int main() {
    vector<int> nums = {3, 2, 2, 5};
    int k = 6;
    cout << "Minimum cost is " << minCostWordWrap(nums, k) << endl;
    return 0;
}
