#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<vector<int>> result;
        set<vector<int>> uniquePermutations;
        
        sort(arr.begin(), arr.end());
        do {
            uniquePermutations.insert(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        
        for (const auto &perm : uniquePermutations) {
            result.push_back(perm);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 1};
    vector<int> arr2 = {4, 5};

    vector<vector<int>> perms1 = sol.uniquePerms(arr1, arr1.size());
    vector<vector<int>> perms2 = sol.uniquePerms(arr2, arr2.size());

    cout << "Permutations for arr1:" << endl;
    for (const auto &perm : perms1) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Permutations for arr2:" << endl;
    for (const auto &perm : perms2) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
