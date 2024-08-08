class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        vector<int> nextg(m,-1); bool te=false;
        for (int i = 0; i < m-1; i++) {
           te = false;
            for (int j = i + 1; j < m; j++) {
                if (nums2[i] < nums2[j]) {
                    nextg[i] = nums2[j];
                    te = true;
                    break;
                }
            }
            if (!te)
                nextg[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j])
                    ans.push_back(nextg[j]);
            }
        }
        return ans;
    }
};