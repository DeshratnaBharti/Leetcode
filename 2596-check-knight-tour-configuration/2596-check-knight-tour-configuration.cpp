class Solution {
public:
    int n;
    bool isValid(vector<vector<int>>&grid,int r, int c, int expVal){
        if(r<0 or c<0 or r>=n or c>=n or grid[r][c] != expVal) return false;
        if(expVal == n*n -1) return true;
        int ans1 = isValid(grid,r-2,c+1,expVal+1);
        int ans2 = isValid(grid,r-1,c+2,expVal+1);
        int ans3 = isValid(grid,r+1,c+2,expVal+1);
        int ans4 = isValid(grid,r+2,c+1,expVal+1);
        int ans5 = isValid(grid,r+2,c-1,expVal+1);
        int ans6 = isValid(grid,r+1,c-2,expVal+1);
        int ans7 = isValid(grid,r-1,c-2,expVal+1);
        int ans8 = isValid(grid,r-2,c-1,expVal+1);
        return ans1 or ans2 or ans3 or ans4 or ans5 or ans6 or ans7 or ans8;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
         n = grid.size();
        return isValid(grid,0,0,0);
    }
};