class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int ans = strs[0].size();
        
        for (int i = 1; i < strs.size(); ++i) {
            int count = 0;
            string temp1 = strs[i - 1];
            string temp2 = strs[i];
            
            for (int j = 0; j < min(temp1.size(), temp2.size()); ++j) {
                if (temp1[j] == temp2[j]) {
                    count++;
                } else {
                    break;
                }
            }
            ans = min(count, ans);
        }

        return strs[0].substr(0, ans);
    }
};
