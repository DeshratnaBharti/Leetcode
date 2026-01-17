class Solution {
public:
    int maxProfitMemoHelper(vector<int>& prices, int i, int min_price, vector<int>& dp) {
        if (i == prices.size()) return 0; 

        if (dp[i] != -1) return dp[i]; 

        min_price = min(min_price, prices[i]); 
        int profit_today = prices[i] - min_price; 
        int profit_future = maxProfitMemoHelper(prices, i + 1, min_price, dp); 

        return dp[i] = max(profit_today, profit_future); 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, -1); 
        return maxProfitMemoHelper(prices, 0, INT_MAX, dp);
    }
    
};