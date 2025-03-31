class Solution {
public:

         vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

    void dfs(vector<vector<int>>& arr, int i, int j) {
        arr[i][j] = 2; 
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && arr[new_i][new_j] == 1) {
                dfs(arr, new_i, new_j);  
            }
        }
    }
    int numEnclaves(vector<vector<int>>& arr) {
          if (arr.empty()) return 0;
        m = arr.size();
        n = arr[0].size();

        // Step 1: Perform DFS for boundary 'O' regions
        for (int j = 0; j < n; j++) {
            if (arr[0][j] == 1) dfs(arr, 0, j);
            if (arr[m-1][j] == 1) dfs(arr, m-1, j);
        }
        for (int i = 0; i < m; i++) {
            if (arr[i][0] == 1) dfs(arr, i, 0);
            if (arr[i][n-1] == 1) dfs(arr, i, n-1);
        }
           int count =0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1)count++;  // Change surrounded 'O' to 'X'
               
            }
        }
        return count;
    
    }
};