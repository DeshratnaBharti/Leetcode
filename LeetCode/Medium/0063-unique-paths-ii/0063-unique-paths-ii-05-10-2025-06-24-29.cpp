class Solution {
public:
      int t[101][101];
    int m, n;
    vector<vector<int>>grid;
    int f(int i, int j) {
        if (i == m - 1 && j == n - 1) return 1;
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(grid[i][j]==1) return 0;
        if (t[i][j] != -1) return t[i][j];

        return t[i][j] = f(i + 1, j) + f(i, j + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid =obstacleGrid;
        m = grid.size();
        n= grid[0].size();
         memset(t, -1, sizeof(t));  
         if(grid[m-1][n-1]==1) return 0;
       return f(0,0);

    }
};