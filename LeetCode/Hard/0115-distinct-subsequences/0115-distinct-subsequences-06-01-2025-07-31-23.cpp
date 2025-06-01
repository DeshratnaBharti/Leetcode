class Solution {
public:
    int f(string &s, string &t, int n, int m, int i, int j, vector<vector<int>> &dp){
        if (j == m) return 1; // Successfully formed subsequence
        if (i == n) return 0; // Exhausted string s but t not formed
        
        if (dp[i][j] != -1) return dp[i][j]; // Memoized result
        
        int take = 0, skip = 0;
        
        if (s[i] == t[j]) {
            take = f(s, t, n, m, i+1, j+1, dp); // Include s[i] in the subsequence
        }
        
        skip = f(s, t, n, m, i+1, j, dp); // Skip s[i]

        return dp[i][j] = take + skip;
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table
        
        return f(s, t, n, m, 0, 0, dp);
    }
};
