class Solution {
public:
    // Function to calculate the maximum profit from stock prices
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0; // Initialize total profit to 0

        // Iterate through the price vector, starting from the second element
        for (int i = 1; i < prices.size(); ++i) {
            // Calculate the profit by buying at prices[i-1] and selling at prices[i]
            // Add the profit to totalProfit if it is positive
            totalProfit += std::max(0, prices[i] - prices[i - 1]);
        }

        // Return the total accumulated profit
        return totalProfit;
    }
};
