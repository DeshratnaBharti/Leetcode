class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

    void dfs(vector<vector<char>>& arr, int i, int j) {
        arr[i][j] = 'b';  // Mark as boundary-connected
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && arr[new_i][new_j] == 'O') {
                dfs(arr, new_i, new_j);  // Recursively explore neighbors
            }
        }
    }

    void solve(vector<vector<char>>& arr) {
        if (arr.empty()) return;
        m = arr.size();
        n = arr[0].size();

        // Step 1: Perform DFS for boundary 'O' regions
        for (int j = 0; j < n; j++) {
            if (arr[0][j] == 'O') dfs(arr, 0, j);
            if (arr[m-1][j] == 'O') dfs(arr, m-1, j);
        }
        for (int i = 0; i < m; i++) {
            if (arr[i][0] == 'O') dfs(arr, i, 0);
            if (arr[i][n-1] == 'O') dfs(arr, i, n-1);
        }

        // Step 2: Transform the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'O') arr[i][j] = 'X';  // Change surrounded 'O' to 'X'
                else if (arr[i][j] == 'b') arr[i][j] = 'O';  // Restore boundary-connected 'O'
            }
        }
    }
};
