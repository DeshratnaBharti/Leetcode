class Solution {
public:
    int t[101][101]; // Fixed-size array, but could use vector for flexibility
    vector<vector<int>> grid;
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        int p = grid.size();
        int q = grid[0].size();

        if (grid[p-1][q-1] == 1 || grid[0][0] == 1) return 0; // If start or end is blocked

        memset(t, -1, sizeof(t));
        t[p-1][q-1] = 1;

        // Fill last column correctly
        for (int i = p - 2; i >= 0; i--) {
            if (grid[i][q-1] == 1) t[i][q-1] = 0;
            else t[i][q-1] = t[i+1][q-1]; // Carrying values forward
        }

        // Fill last row correctly
        for (int i = q - 2; i >= 0; i--) {
            if (grid[p-1][i] == 1) t[p-1][i] = 0;
            else t[p-1][i] = t[p-1][i+1]; // Carrying values forward
        }

        // Fill the rest of the matrix
        for (int i = p - 2; i >= 0; i--) {
            for (int j = q - 2; j >= 0; j--) {
                if (grid[i][j] == 1) t[i][j] = 0;
                else t[i][j] = t[i+1][j] + t[i][j+1]; // Using bottom and right values
            }
        }

        return t[0][0];
    }
};
