class Solution {
public:
    int countPalindromes(string s) {
        constexpr int MOD = 1'000'000'007;
        int n = s.size();
        long ans = 0;

        // Count prefix pairs: prefix[i][a][b] = number of times digit pair (a,b) appears before index i
        vector<vector<int>> prefix(10, vector<int>(10, 0));
        vector<int> countLeft(10, 0);

        // Suffix pair counts: suffix[i][a][b] = number of times digit pair (a,b) appears after index i
        vector<vector<int>> suffix(10, vector<int>(10, 0));
        vector<int> countRight(10, 0);

        // First, build suffix counts
        for (int i = n - 1; i >= 0; --i) {
            int d = s[i] - '0';
            for (int j = 0; j < 10; ++j) {
                suffix[d][j] += countRight[j];
            }
            countRight[d]++;
        }

        // Now iterate through each character as the center of the palindrome
        for (int i = 0; i < n; ++i) {
            int mid = s[i] - '0';

            // Remove current digit from suffix
            countRight[mid]--;
            for (int j = 0; j < 10; ++j) {
                suffix[mid][j] -= countRight[j];
            }

            // Count combinations of prefix and suffix pairs
            for (int a = 0; a < 10; ++a) {
                for (int b = 0; b < 10; ++b) {
                    ans = (ans + 1L * prefix[a][b] * suffix[b][a]) % MOD;
                }
            }

            // Update prefix counts
            for (int j = 0; j < 10; ++j) {
                prefix[j][mid] += countLeft[j];
            }
            countLeft[mid]++;
        }

        return static_cast<int>(ans);
    }
};
