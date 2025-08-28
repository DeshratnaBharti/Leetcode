class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

    int n = grid.size();
    map<int, vector<int>> diag;

    // Step 1: Collect all diagonals using key = i - j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            diag[i - j].push_back(grid[i][j]);
        }
    }

    // Step 2: Sort each diagonal based on position
    for (auto& [key, vec] : diag) {
        if (key >= 0) {
            sort(vec.rbegin(), vec.rend()); // bottom-left → descending
        } else {
            sort(vec.begin(), vec.end());   // top-right → ascending
        }
    }

    // Step 3: Put sorted values back into grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = diag[i - j].front();
            diag[i - j].erase(diag[i - j].begin());
        }
    }

    return grid;


        

    }
};