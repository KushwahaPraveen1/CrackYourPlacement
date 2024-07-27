class Solution {
public:
#define ll long long int
vector<vector<ll>>dp;
int solve(int m,int n)
{
 if(m==0&&n==0)return 1;
        if(m<0||n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];

        int up=solve(m-1,n);
        int down=solve(m,n-1);
        dp[m][n]=up+down;
        return dp[m][n];
}
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<ll>(n,-1));
       return solve(m-1,n-1);
    }
};