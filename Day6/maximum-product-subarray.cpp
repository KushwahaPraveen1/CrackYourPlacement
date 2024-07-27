class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int currentProduct = 1;

        for (int i = 0; i < nums.size(); i++) {
            currentProduct *= nums[i];
            maxProduct = max(currentProduct, maxProduct);
            if (currentProduct == 0) {
                currentProduct = 1;
            }
        }

        currentProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            currentProduct *= nums[i];
            maxProduct = max(currentProduct, maxProduct);
            if (currentProduct == 0) {
                currentProduct = 1;
            }
        }

        return maxProduct;
    }
};
