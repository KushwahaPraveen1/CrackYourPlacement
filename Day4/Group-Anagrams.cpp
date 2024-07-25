class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> map; 
        vector<vector<string>> ans; 
        
        for(int i=0;i<strs.size();i++){
                string p = strs[i]; 
                sort(p.begin(), p.end()); 
                map[p].push_back(strs[i]);
        }
        
        for(auto j= map.begin();j!=map.end();j++){
            ans.push_back(j->second);
        }
     
        return ans;
    }
};