#include <vector>
#include <algorithm>

class Solution
{
public:
    // Function to find floor of x
    // v: vector of elements (assumed to be sorted)
    // x: element whose floor is to find
    int findFloor(const std::vector<long long> &v, long long x)
    {
        // Edge case: empty vector
        if (v.empty())
        {
            return -1;
        }

        int low = 0;
        int high = v.size() - 1;
        int result = -1; // Default result if no floor is found

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (v[mid] == x)
            {
                return mid; // Exact match
            }
            else if (v[mid] < x)
            {
                result = mid; // Potential floor found
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return result;
    }
};
