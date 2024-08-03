class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
       deque<pair<int, int>> dq;
        int max_value = INT_MIN;
        
        for (const auto& point : points) {
            int x = point[0], y = point[1];  while (!dq.empty() && x - dq.front().second > k) {
                dq.pop_front();
            }  if (!dq.empty()) {
                max_value = max(max_value, y + x + dq.front().first);
            }  while (!dq.empty() && y - x >= dq.back().first) {
                dq.pop_back();
            }  dq.emplace_back(y - x, x);
        }
        
        return max_value;  
    }
};