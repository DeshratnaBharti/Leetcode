class Solution {
public:
    vector<vector<int>> grid;

    int f(int r, int c) {
        if (r == grid.size() - 1 && c == grid[0].size() - 1) return grid[r][c]; // Base case
        if (r >= grid.size() || c >= grid[0].size()) return INT_MAX; // Out of bounds

        return grid[r][c] + min(f(r + 1, c), f(r, c + 1)); // Move down or right
    }

    int minPathSum(vector<vector<int>>& triangle) {
        grid = triangle;
        return f(0, 0);
    }
};
