class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Update heights based on the current row
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, maxHist(heights));
        }

        return maxArea;
    }

private:
    int maxHist(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        int i = 0;

        while (i < heights.size()) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i++);
            } else {
                int top_val = heights[s.top()];
                s.pop();
                int area = top_val * (s.empty() ? i : i - s.top() - 1);
                max_area = max(max_area, area);
            }
        }

        while (!s.empty()) {
            int top_val = heights[s.top()];
            s.pop();
            int area = top_val * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
