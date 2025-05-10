class Solution {
public:
    int t[101][101];
    int m, n;

    int f(int i, int j) {
        if (i == m - 1 && j == n - 1) return 1;
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        if (t[i][j] != -1) return t[i][j];

        return t[i][j] = f(i + 1, j) + f(i, j + 1);
    }

    int uniquePaths(int p, int q) {
        m = p;
        n = q;
        memset(t, -1, sizeof(t));  // Corrected memset usage
        return f(0, 0);
    }
};
