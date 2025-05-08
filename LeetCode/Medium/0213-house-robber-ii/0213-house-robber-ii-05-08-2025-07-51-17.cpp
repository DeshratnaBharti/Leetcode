class Solution {
public:
    int f(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        vector<int> excludeFirst(arr.begin() + 1, arr.end());
        vector<int> excludeLast(arr.begin(), arr.end() - 1);

        return max(f(excludeFirst), f(excludeLast));
    }
};
