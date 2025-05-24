// User function Template for C++

class Solution {
  public:
    int n;
    vector<vector<int>> dp;

    int f(vector<int> &price, int i, int length) {
        if (i == n || length == 0) return 0;
        if (dp[i][length] != -1) return dp[i][length];

        int take = 0;
        if (i + 1 <= length) {  // Since rod lengths are 1-based (index i corresponds to length i+1)
            take = price[i] + f(price, i, length - (i + 1));
        }
        int not_take = f(price, i + 1, length);

        return dp[i][length] = max(take, not_take);
    }

    int cutRod(vector<int> &price) {
        n = price.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return f(price, 0, n);
    }
};
