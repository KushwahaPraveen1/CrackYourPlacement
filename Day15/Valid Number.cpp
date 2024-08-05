class Solution {
public:
    bool isNumber(string s) {
        return regex_match(s, regex("[+-]?((\\.[0-9]+)|([0-9]+\\.)|([0-9]+\\.[0-9]+)|([0-9]+))([eE][+-]?[0-9]+)?"));
    }
};