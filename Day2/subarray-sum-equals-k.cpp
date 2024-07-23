class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            if (prefixSum == k) {
                cnt++;
            }
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                cnt += prefixSumCount[prefixSum - k];
            }
            prefixSumCount[prefixSum]++;
        }

        return cnt;
    }
};