class Solution {
public:
    int m, n;
    int dp[71][71][71]; 
    
    int f(vector<vector<int>>& grid, int row, int c1, int c2) {
        if (row >= m) return 0;
        if (dp[row][c1][c2] != -1) return dp[row][c1][c2]; 
        
        int cherry = grid[row][c1];
        if (c1 != c2) cherry += grid[row][c2];

        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newc1 = c1 + i;
                int newc2 = c2 + j;
                if (newc1 >= 0 && newc1 < n && newc2 >= 0 && newc2 < n) {
                    ans = max(ans, f(grid, row + 1, newc1, newc2));
                }
            }
        }
        return dp[row][c1][c2] = ans + cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp)); 
        return f(grid, 0, 0, n - 1);
    }
};
