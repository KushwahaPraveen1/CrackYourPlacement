class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& vec) {
        stack<int>st;vector<int>ans(vec.size());
            for (int i = vec.size() - 1; i >= 0; i--) { while (!st.empty() && vec[st.top()] <= vec[i]) {
                st.pop();
            }
             if (st.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = st.top() - i;
            }
            
             st.push(i);
        }
        return ans;

    }
};