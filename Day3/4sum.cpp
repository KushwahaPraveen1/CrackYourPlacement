class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> temp;
        int m, n;
        if (nums.size() < 4)
            return ans;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                m = j + 1;
                n = nums.size() - 1;
                {
                    while (m < n)
                    {
                        long long sum = (long long)nums[i] +
                                        (long long)nums[j] +
                                        (long long)nums[m] + 
                                        (long long)nums[n];
                        if (sum < target)
                            m++;
                        else if (sum > target)
                            n--;
                        else
                        {
                            temp.insert({nums[i], nums[j], nums[m], nums[n]});
                            m++;
                            n--;
                        }
                    }
                }
            }
        }
        for (auto it : temp)
        {
            ans.push_back(it);
        }
        return ans;
    }
};