class Solution {
public:
     int m,n;
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i>=m or j>=n) return 0;
        if(grid[i][j]==0) return 0;
        int right = solve(i,j+1,grid);
        int diag = solve(i+1,j+1,grid);
        int below = solve(i+1,j,grid);

        return 1 + min({right,diag,below});
    }
    int countSquares(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans += solve(i,j,grid);
                }
            }
        }
        return ans;
    }
};