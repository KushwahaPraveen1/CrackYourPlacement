class Solution {
public:
    int calculate(string s) {
        stack<int> s1;
        stack<char> s2;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            continue;
            else if(isdigit(s[i]))
            {
                string temp = "";
                temp+=s[i];
                while(i+1<s.length() && isdigit(s[i+1]))
                {
                    i++;
                    temp+=s[i];
                }
                int t = stoi(temp);
                s1.push(t);
            }
            else
            {
                if(s2.empty())
                s2.push(s[i]);
                else if(s2.top()=='*' || s2.top()=='/')
                {
                    int temp;
                    int n1 = s1.top();
                    s1.pop();
                    int n2=s1.top();
                    s1.pop();

                    if(s2.top()=='*')
                    {
                        temp = n2*n1;
                        s1.push(temp);
                        s2.pop();
                    }
                    else
                    {
                        temp = n2/n1;
                        s1.push(temp);
                        s2.pop();
                    }
                    i--;
                }
                else if((s2.top()=='+' || s2.top()=='-') && (s[i]=='+' || s[i]=='-'))
                {
                    int temp;
                    int n1 = s1.top();
                    s1.pop();
                    int n2=s1.top();
                    s1.pop();

                    if(s2.top()=='+')
                    {
                        temp = n2+n1;
                        s1.push(temp);
                        s2.pop();
                    }
                    else
                    {
                        temp = n2-n1;
                        s1.push(temp);
                        s2.pop();
                    }
                    i--;
                }
                else
                {
                    s2.push(s[i]);
                }               
            }
        }
        while(s1.size()!=1)
        {
            int n1 = s1.top();
            s1.pop();
            int n2 = s1.top();
            s1.pop();

            char x = s2.top();
            s2.pop();

            if(x=='+')
            {
                int temp = n2+n1;
                s1.push(temp);
            }
            else if(x=='-')
            {
                int temp = n2-n1;
                s1.push(temp);
            }
            else if(x=='*')
            {
                int temp = n2*n1;
                s1.push(temp);
            }
            else
            {
                int temp = n2/n1;
                s1.push(temp);
            }  
        }
        return s1.top();
    }
};