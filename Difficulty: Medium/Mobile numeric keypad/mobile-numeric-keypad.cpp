class Solution {
public:
    int t[4][3][16];

    int solve(int i, int j, int n, vector<vector<int>> &mat) {
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || mat[i][j] == -1) return 0;
        if(n == 1) return 1;
        if(t[i][j][n] != -1) return t[i][j][n];

        int curr  = solve(i, j,   n - 1, mat);
        int left  = solve(i, j - 1, n - 1, mat);
        int right = solve(i, j + 1, n - 1, mat);
        int up    = solve(i - 1, j, n - 1, mat);
        int down  = solve(i + 1, j, n - 1, mat);

        return t[i][j][n] = curr + left + right + up + down;
    }

    int getCount(int n) {
        vector<vector<int>> mat = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
            {-1, 1, -1}
        };

        memset(t, -1, sizeof(t));
        int ans = 0;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(mat[i][j] != -1) {
                    ans += solve(i, j, n, mat);
                }
            }
        }

        return ans;
    }
};
