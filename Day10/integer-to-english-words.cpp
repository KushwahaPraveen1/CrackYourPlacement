#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                               "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num == 0) return "Zero";
        string result = "";
        if (num >= 100) {
            result += below_20[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            result += tens[num / 10 - 1] + " ";
            num %= 10;
        }
        if (num > 0) {
            result += below_20[num] + " ";
        }
        return result;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }
        while (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << "Number 123: " << sol.numberToWords(123) << endl;
    cout << "Number 12345: " << sol.numberToWords(12345) << endl;
    cout << "Number 1234567: " << sol.numberToWords(1234567) << endl;
    return 0;
}
