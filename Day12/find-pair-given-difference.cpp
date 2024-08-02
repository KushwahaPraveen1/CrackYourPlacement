#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int hasPairWithDifference(const vector<int>& arr, int n, int x) {
    unordered_set<int> seen;

    for (int a : arr) {
        if (seen.find(a + x) != seen.end() || seen.find(a - x) != seen.end()) {
            return 1;
        }
        seen.insert(a);
    }
    
    return -1;
}

int main() {
    int n = 6;
    int x = 78;
    vector<int> arr = {5, 20, 3, 2, 5, 80};
    
    int result = hasPairWithDifference(arr, n, x);
    cout << result << endl; 
    
    return 0;
}
