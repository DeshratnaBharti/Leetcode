class Solution {
public:
    int dp[302][302];

    int burst(vector<int>& nums, int i, int j) {
        if (i + 1 == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for (int k = i + 1; k < j; ++k) {
            int coins = nums[i] * nums[k] * nums[j];
            int left = burst(nums, i, k);
            int right = burst(nums, k, j);
            ans = max(ans, coins + left + right);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> extended(n + 2, 1);

        for (int i = 0; i < n; ++i)
            extended[i + 1] = nums[i];

        memset(dp, -1, sizeof(dp));
        return burst(extended, 0, n + 1);
    }
};
