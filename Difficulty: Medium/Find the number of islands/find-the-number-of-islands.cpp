//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    // DFS function har cell ko visit karne ke liye
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[i][j] = true;
        
        // Har direction mein traverse karein
        for (auto dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // Check karein agar cell grid ke andar hai aur wo land (L) hai
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && 
                grid[new_i][new_j] == 'L' && !visited[new_i][new_j]) {
                dfs(new_i, new_j, visited, grid);
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int cc = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Grid mein har cell ko check karein
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Agar cell land hai aur visit nahi kiya gaya hai, to naya island mila
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    dfs(i, j, visited, grid); // DFS chalayenge
                    cc++; // Island count increment karein
                }
            }
        }
        return cc;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends