class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>st1,st2;
        for(auto it:s)
        {
            if(it=='#')
            {
                if(!st1.empty())
                {
                    st1.pop();
                }
            }
           else st1.push(it);
        }for(auto it:t)
        {
            if(it=='#')
            {
                if(!st2.empty())
                {
                    st2.pop();
                }
            }
            else st2.push(it);
        }
        
if(st1.empty()&&st2.empty())return 1;
        while(!st1.empty()&&!st2.empty())
        {
            if(st1.top()!=st2.top())return 0;
            st1.pop();st2.pop();
}
if(st1.empty()&&st2.empty())return 1;
if(!st1.empty()||!st2.empty())return 0;
return 1;
    }
};