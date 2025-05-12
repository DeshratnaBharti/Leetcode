class Solution {
public:
    int m;
    vector<vector<int>>grid;
    int f(int i,int j){
        if(i==m-1) return grid[i][j];
        return grid[i][j]+min(f(i+1,j+1),f(i+1,j));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        grid = triangle;
        m = grid.size();
        return f(0,0);
    }
};