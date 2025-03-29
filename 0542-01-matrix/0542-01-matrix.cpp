#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX)); // Initialize with INT_MAX
        queue<P> que;

        // Step 1: Enqueue all `0` cells and set their distance as 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        // Step 2: Perform BFS
        while (!que.empty()) {
            P curr = que.front();
            que.pop();
            int i = curr.first;
            int j = curr.second;

            for (auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                // Check boundary conditions and relax distances
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                    if (res[new_i][new_j] > res[i][j] + 1) {
                        res[new_i][new_j] = res[i][j] + 1;
                        que.push({new_i, new_j});
                    }
                }
            }
        }

        return res;
    }
};
