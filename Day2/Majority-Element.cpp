class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(), nums.end());

    int max_freq = 0;
    int cnt = 1;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            cnt++;
        } else {
            if (cnt > (nums.size() / 2)) {
                max_freq = max(max_freq, cnt);
                return nums[i];
            }
            cnt = 1;
        }
    }

    if (cnt > (nums.size() / 2)) {
        max_freq = max(max_freq, cnt);
        return nums[nums.size() - 1];
    }return 0;   
    }
};