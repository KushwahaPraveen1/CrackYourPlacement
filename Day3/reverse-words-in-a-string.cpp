class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string temp = "";
        vector<string> ans;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                temp = "";
            }

            while (s[i] != ' ' && i < s.length()) {
                temp += s[i];
                i++;
            }
            if (temp != "")
                ans.push_back(temp);
            temp = "";
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            str += ans[i];
            if (i != 0)
                str += ' ';
        }

        return str;
    }
};