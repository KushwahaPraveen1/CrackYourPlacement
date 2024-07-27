class Solution {
    #define ll long long int
    const int MOD = 1000000007;
public:
    vector<vector<ll>> jump{
        {4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}
    };
    vector<vector<ll>> dp;

    int knightDialer(int n) {
        dp.resize(n, vector<ll>(10, -1));
        ll ans = 0;
        for (ll i = 0; i < 10; ++i) {
            ans = (ans + solve(n - 1, i)) % MOD;
        }
        return ans;
    }

    ll solve(ll rem, ll digit) {
        if (rem == 0) return 1;
        if (dp[rem][digit] != -1) return dp[rem][digit];

        ll temp = 0;
        for (auto it : jump[digit]) {
            temp = (temp + solve(rem - 1, it)) % MOD;
        }
        dp[rem][digit] = temp;
        return dp[rem][digit];
    }
};
