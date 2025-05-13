class Solution {
public:
    vector<vector<int>> grid,dp;
    int m, n;
    

    int f(int row, int col) {
        if (col < 0 || col >= n) return INT_MAX; 
        if (row == m - 1) return grid[row][col];  
        if (dp[row][col] != INT_MAX) return dp[row][col]; 

        int down = f(row + 1, col);
        int left = f(row + 1, col - 1);
        int right = f(row + 1, col + 1);

        return dp[row][col] = grid[row][col] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        grid = matrix;
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, INT_MAX)); 

        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, f(0, i)); 
        }
        return mini;
    }
};
