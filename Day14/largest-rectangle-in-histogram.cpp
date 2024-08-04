class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int result = 0;
        stack<pair<int, int>> stack;
        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i])
            {
                int index = stack.top().first;
                int width = i - index;
                int height = stack.top().second;
                stack.pop();
                result = max(result, height * width);
                start = index;
            }
            stack.push({start, heights[i]});
        }
        while (!stack.empty())
        {
            int width = heights.size() - stack.top().first;
            int height = stack.top().second;
            stack.pop();
            result = max(result, height * width);
        }
        return result;
    }
};