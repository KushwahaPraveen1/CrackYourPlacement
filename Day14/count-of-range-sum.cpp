#include <algorithm>
#include <vector>

class Solution {
public:
    int countRangeSum(std::vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        std::vector<long long> prefixSums(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        return countWhileMergeSort(prefixSums, 0, n + 1, lower, upper);
    }

private:
    int countWhileMergeSort(std::vector<long long>& sums, int start, int end,
                            int lower, int upper) {
        if (end - start <= 1)
            return 0;

        int mid = start + (end - start) / 2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper) +
                    countWhileMergeSort(sums, mid, end, lower, upper);

        int j = mid, k = mid, t = mid;
        std::vector<long long> cache(end - start, 0);
        int r = 0;

        for (int i = start, cacheIdx = 0; i < mid; ++i, ++cacheIdx) {
            while (j < end && sums[j] - sums[i] < lower)
                ++j;
            while (k < end && sums[k] - sums[i] <= upper)
                ++k;
            while (t < end && sums[t] < sums[i])
                cache[cacheIdx++] = sums[t++];
            cache[cacheIdx] = sums[i];
            count += k - j;
        }

        std::copy(cache.begin(), cache.begin() + t - start,
                  sums.begin() + start);
        return count;
    }
};
