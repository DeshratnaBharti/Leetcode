class Solution {
public:
    int minInsertions(string s) {
         int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        for (int startIdx = n - 2; startIdx >= 0; --startIdx) { 
            for (int endIdx = startIdx + 1; endIdx < n; ++endIdx) { 
                if (s[startIdx] == s[endIdx]) {
                    
                    dp[startIdx][endIdx] = dp[startIdx + 1][endIdx - 1];
                } else {
                
                    dp[startIdx][endIdx] = min(dp[startIdx + 1][endIdx], dp[startIdx][endIdx - 1]) + 1;
                }
            }
        }
      
     
        return dp[0][n - 1];
    }
};