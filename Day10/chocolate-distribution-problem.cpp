#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        if (m == 0 || n == 0) 
            return 0;

        sort(a.begin(), a.end());

        if (n < m) 
            return -1;

        long long min_diff = LLONG_MAX;

        for (long long i = 0; i + m - 1 < n; i++) {
            long long diff = a[i + m - 1] - a[i];
            if (diff < min_diff) 
                min_diff = diff;
        }
        return min_diff;
    }
};

int main() {
    Solution sol;
    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
    long long n = a.size();
    long long m = 5;
    cout << sol.findMinDiff(a, n, m) << endl; // Output: 6

    a = {7, 3, 2, 4, 9, 12, 56};
    n = a.size();
    m = 3;
    cout << sol.findMinDiff(a, n, m) << endl; // Output: 2

    return 0;
}
