#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string canPermute(vector<int>& a, vector<int>& b, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] + b[i] < k) {
            return "No";
        }
    }

    return "Yes";
}

int main() {
    vector<int> a1 = {2, 1, 3};
    vector<int> b1 = {7, 8, 9};
    int k1 = 10;
    cout << canPermute(a1, b1, k1) << endl; 

    vector<int> a2 = {1, 2, 2, 1};
    vector<int> b2 = {3, 3, 3, 4};
    int k2 = 5;
    cout << canPermute(a2, b2, k2) << endl; 

    return 0;
}
