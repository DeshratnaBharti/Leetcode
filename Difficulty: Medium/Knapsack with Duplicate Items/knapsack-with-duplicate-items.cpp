// User function Template for C++

class Solution {
  public:
  //top down approach
vector<vector<int>> dp;
    int f(vector<int>& val, vector<int>& wt, int capacity, int i) {
        if (i == val.size()) return 0;
        if (dp[i][capacity] != -1) return dp[i][capacity];
    
        int take = 0;
        if (wt[i] <= capacity) {
            take = val[i] + f(val, wt, capacity - wt[i], i);
        }
        int not_take = f(val, wt, capacity, i + 1);
    
        return dp[i][capacity] = max(take, not_take);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        dp.resize(val.size(), vector<int>(capacity + 1, -1));
        return f(val, wt, capacity, 0);
    }
};
