class Solution {
public:
unordered_map<int, int> dp;
int solve(int n,string s)
{

    if(n==0)return 1;
    if(s[0]=='0')return 0;
       if (dp.find(n) != dp.end()) return dp[n];
    int single=0;   
    int doubl=0;
    if (n > 1 && (s[0] == '1' || (s[0] == '2' && s[1] >= '0' && s[1] <= '6'))) {
            doubl = solve(n - 2, s.substr(2));
        }
     single=solve(n-1,s.substr(1));
    return dp[n]=single+doubl;
}
    int numDecodings(string s) {
        // dp.resize(s.length()+1,vector<int>())
     return solve(s.length(),s);  
    }
};