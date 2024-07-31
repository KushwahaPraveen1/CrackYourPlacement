#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(result, "", 0, 0, n);
        return result;
    }

private:
    void generateParenthesisHelper(vector<string> &result, string current, int open, int close, int max) {
        if (current.length() == 2 * max) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            generateParenthesisHelper(result, current + '(', open + 1, close, max);
        }
        if (close < open) {
            generateParenthesisHelper(result, current + ')', open, close + 1, max);
        }
    }
};

int main() {
    Solution sol;
    int n1 = 3;
    int n2 = 1;

    vector<string> result1 = sol.generateParenthesis(n1);
    vector<string> result2 = sol.generateParenthesis(n2);

    cout << "Combinations for n = " << n1 << ":" << endl;
    for (const auto& str : result1) {
        cout << str << endl;
    }

    cout << "Combinations for n = " << n2 << ":" << endl;
    for (const auto& str : result2) {
        cout << str << endl;
    }

    return 0;
}
