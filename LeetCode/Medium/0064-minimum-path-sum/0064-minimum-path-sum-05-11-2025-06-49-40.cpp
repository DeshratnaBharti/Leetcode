class Solution {
public:
    vector<vector<int>> grid;
    int t[201][201];

    int f(int r, int c) {
        if (r == grid.size() - 1 && c == grid[0].size() - 1) return grid[r][c]; // Base case
        if (r >= grid.size() || c >= grid[0].size()) return INT_MAX; // Out of bounds
        if(t[r][c]!=-1) return t[r][c];

        return  t[r][c]=  grid[r][c] + min(f(r + 1, c), f(r, c + 1)); // Move down or right
    }

    int minPathSum(vector<vector<int>>& triangle) {
        grid = triangle;
        memset(t,-1,sizeof(t));
        return f(0, 0);
    }
};
