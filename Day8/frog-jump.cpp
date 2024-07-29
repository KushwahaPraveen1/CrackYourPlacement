class Solution
{
public:
    bool ans(vector<int> vect)
    {
        int n = vect.size();
        unordered_map<int, unordered_set<int>> mp;
        mp[0].insert(1);
        for (auto i : vect)
        {
            for (int jump : mp[i])
            {
                if (jump + i == vect[n - 1])
                    return true;
                if (jump - 1 > 0)
                    mp[jump + i].insert(jump - 1);
                mp[jump + i].insert(jump);
                mp[jump + i].insert(jump + 1);
            }
        }
        return false;
    }
    bool canCross(vector<int> &stones) { return ans(stones); }
};