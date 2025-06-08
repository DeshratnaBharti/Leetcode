class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int noStockProfit = 0;
        int holdProfit = 0; 
        int oneStockProfit = -prices[0]; // Assume we bought the first stock

       
        for (int i = 1; i < prices.size(); ++i) {
            
            int newNoStockProfit = max(noStockProfit, oneStockProfit + prices[i]);
          
            oneStockProfit = max(oneStockProfit, holdProfit - prices[i]);
          
           
            holdProfit = noStockProfit;
           
            noStockProfit = newNoStockProfit;
        }
      
        return noStockProfit;
    }
};