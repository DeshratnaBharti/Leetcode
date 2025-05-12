class Solution {
public:
    int m;
    vector<vector<int>>grid,dp;
    int f(int i,int j){
        if(i==m-1) return grid[i][j];
        if(dp[i][j]!= -1) return dp[i][j];
        return dp[i][j]=  grid[i][j]+min(f(i+1,j+1),f(i+1,j));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       // dp.clear();
        dp.resize(205,vector<int>(205,-1));
        grid = triangle;
        m = grid.size();
        return f(0,0);
    }
};