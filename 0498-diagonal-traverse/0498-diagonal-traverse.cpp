class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();         // rows
        int n = mat[0].size();      // columns
        vector<int> result;

        for (int d = 0; d < m + n - 1; d++) {
            vector<int> temp;

            // Traverse each diagonal
            for (int i = 0; i < m; i++) {
                int j = d - i;
                if (j >= 0 && j < n) {
                    temp.push_back(mat[i][j]);
                }
            }

            // Even diagonal → reverse
            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            // Add to result
            for (int val : temp) {
                result.push_back(val);
            }
        }

        return result;
    }
};
