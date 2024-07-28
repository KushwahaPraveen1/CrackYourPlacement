class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int n, int t, vector<int> nums)
    {
        if (n == 0)
        {
            if (t % nums[0] == 0)
                return t / nums[0];
            return 1e9;
        }
        if (dp[n][t] != -1)
            return dp[n][t];
        int nottake = 0 + solve(n - 1, t, nums);
        int take = INT_MAX;
        if (nums[n] <= t)
            take = 1 + solve(n, t - nums[n], nums);
        return dp[n][t] = min(take, nottake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        dp.resize(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};