class Solution
{
public:
    string toBinary(int n)
    {
        if (n == 0)
            return "0";
        string binary = "";
        while (n > 0)
        {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        return binary;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            string s = toBinary(i);
            int one = count(s.begin(), s.end(), '1');
            ans.push_back(one);
        }
        return ans;
    }
};