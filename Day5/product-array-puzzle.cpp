#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        vector<long long int> ans;
        long long int prod = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                cnt++;
            else
            {
                prod = prod * nums[i];
            }
        }

        if (cnt == 0)
        {
            for (int i = 0; i < n; i++)
                ans.push_back(prod / nums[i]);
        }
        else if (cnt == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] != 0)
                    ans.push_back(0);
                else
                    ans.push_back(prod);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); 
        for (int i = 0; i < n; i++) 
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}