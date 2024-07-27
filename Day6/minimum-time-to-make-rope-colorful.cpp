class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, ans = 0, n = colors.length(), sum = 0, maxi = 0;
        while (i < n) {
            sum = 0;
            maxi = 0;
            if (colors[i] != colors[i + 1]) {
                i++;
            } else {

                while (i < n - 1 && colors[i] == colors[i + 1]) {
                    maxi = max(maxi, neededTime[i]);
                    sum += neededTime[i];
                    i++;
                }
                maxi = max(maxi, neededTime[i]);
                sum += neededTime[i];

                ans = ans + (sum - maxi);
                i++;
            }
        }
        return ans;
    }
};