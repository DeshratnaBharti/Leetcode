class Solution {
  public:
    vector<vector<int>> dp;
    map<pair<int, int>, set<string>> memo;
    
    // Build the LCS DP table
    void buildDP(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        dp.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    // Backtrack to collect all LCS strings
    set<string> backtrack(string &s1, string &s2, int i, int j) {
        if (i == s1.size() || j == s2.size())
            return {""};

        pair<int, int> key = {i, j};
        if (memo.count(key)) return memo[key];

        set<string> result;
        if (s1[i] == s2[j]) {
            set<string> temp = backtrack(s1, s2, i + 1, j + 1);
            for (const string &str : temp)
                result.insert(s1[i] + str);
        } else {
            if (dp[i + 1][j] >= dp[i][j + 1])
                result = backtrack(s1, s2, i + 1, j);
            if (dp[i][j + 1] >= dp[i + 1][j]) {
                set<string> temp = backtrack(s1, s2, i, j + 1);
                result.insert(temp.begin(), temp.end());
            }
        }

        return memo[key] = result;
    }

    vector<string> allLCS(string &s1, string &s2) {
        buildDP(s1, s2);
        set<string> lcs_set = backtrack(s1, s2, 0, 0);
        return vector<string>(lcs_set.begin(), lcs_set.end());
    }
};
