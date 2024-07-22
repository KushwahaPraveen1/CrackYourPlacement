class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)return 0;
        vector<int>aux(n);
        aux[0]=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            aux[i] = min(aux[i - 1], prices[i]);
        }
        int sum,maxi=0;
        for(int i=0;i<n;i++)
        {
              maxi= max(maxi ,prices[i] - aux[i]);
        }
        return maxi;

        
    }
};