class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int n;
    bool possibleToReach(vector<vector<int>>& grid,int i, int j,int t,vector<vector<bool>>& vis){
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || grid[i][j] > t) return false;
        vis[i][j] = true;
        if(i==n-1 && j==n-1) return true;
        for(auto &dir: directions){
            if(possibleToReach(grid, i+dir[0], j+dir[1], t, vis)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        n = grid.size();
        int l = 0;
        int r = n * n - 1;  
        int res = r;
        while(l <= r){
            int mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if(possibleToReach(grid, 0, 0, mid, vis)){
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};