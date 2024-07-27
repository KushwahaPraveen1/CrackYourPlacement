class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return climbStairsMemo(n, memo);
    }

private:
    int climbStairsMemo(int n, vector<int>& memo) {
        if (n == 0 || n == 1) return 1;
        if (memo[n] != -1) return memo[n];
        memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);
        return memo[n];
    }
};
