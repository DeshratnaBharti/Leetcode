class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0; // Initialize total profit to 0

      
        for (int i = 1; i < prices.size(); ++i) {
            
            totalProfit += std::max(0, prices[i] - prices[i - 1]);
        }

       
        return totalProfit;
    }
};
