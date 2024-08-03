#include <vector>
#include <iostream>

int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            max_profit += prices[i] - prices[i - 1];
        }
    }
    
    return max_profit;
}

int main() {
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::vector<int> prices2 = {1, 2, 3, 4, 5};
    std::vector<int> prices3 = {7, 6, 4, 3, 1};

    std::cout << "Max profit for prices1: " << maxProfit(prices1) << std::endl; // Output: 7
    std::cout << "Max profit for prices2: " << maxProfit(prices2) << std::endl; // Output: 4
    std::cout << "Max profit for prices3: " << maxProfit(prices3) << std::endl; // Output: 0

    return 0;
}
