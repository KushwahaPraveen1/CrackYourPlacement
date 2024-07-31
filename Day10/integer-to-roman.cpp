#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result;

        for (const auto& [value, symbol] : values) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int num1 = 3749;
    int num2 = 58;
    int num3 = 1994;

    cout << "Roman numeral for " << num1 << " is " << sol.intToRoman(num1) << endl;
    cout << "Roman numeral for " << num2 << " is " << sol.intToRoman(num2) << endl;
    cout << "Roman numeral for " << num3 << " is " << sol.intToRoman(num3) << endl;

    return 0;
}
