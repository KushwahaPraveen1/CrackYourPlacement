class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> mp2;         
        string ans;
        for(auto x:t)
        {
            mp2[x]++;
        }

        unordered_map<char,int> mp;
        int mini = INT_MAX;

        int i=0,j=0;
        while(j<n)
        {
            mp[s[j]]++;
            
            int flag = 0;
            for(auto x:mp2)           
            {
                if(mp2[x.first]>mp[x.first])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag==0)           
            {
                while(mp[s[i]]>mp2[s[i]])
                {
                    mp[s[i]]--;

                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                if(mini>j-i+1)
                {
                    mini = min(mini,j-i+1);
                    ans = s.substr(i,j-i+1);
                }
            }

            j++;
        }
        return ans;
    }
};