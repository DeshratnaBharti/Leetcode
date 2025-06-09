class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int numberOfDays = prices.size();
      
        int profit[numberOfDays][2];
    
        memset(profit, 0, sizeof(profit));
      
        profit[0][1] = -prices[0];
      
      
        for (int i = 1; i < numberOfDays; ++i) {
           
            profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i] - fee);
          
            profit[i][1] = max(profit[i - 1][1], profit[i - 1][0] - prices[i]);
        }
      
        return profit[numberOfDays - 1][0];
    }
};