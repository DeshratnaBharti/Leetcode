class Solution {
public:
   int minCoinsRecur(int i, int sum, vector<int> &coins) {
        
        // base case
        if (sum == 0) return 0;
        if (sum <0 || i == coins.size()) return INT_MAX;
        
        int take = INT_MAX;
        
       
        if (coins[i]>0) {
            take = minCoinsRecur(i, sum-coins[i], coins);
            if (take != INT_MAX) take++;
        }
        
     
        int noTake = minCoinsRecur(i+1, sum, coins);
        
        return min(take, noTake);
    }

    int coinChange(vector<int>& coins, int sum) {
         int res = minCoinsRecur(0, sum, coins);
         return res!=INT_MAX?res:-1;
    }
};