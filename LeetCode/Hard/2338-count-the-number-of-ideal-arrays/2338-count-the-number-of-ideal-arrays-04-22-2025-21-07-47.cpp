class Solution {
public:
    const int MOD = 1e9 + 7;

int countIdealArrays(int n, int maxValue) {
    vector<int> dp(maxValue + 1, 1);

    for (int i = 1; i < n; i++) {
        vector<int> new_dp(maxValue + 1, 0);
        for (int x = 1; x <= maxValue; x++) {
            for (int multiple = x; multiple <= maxValue; multiple += x) {
                new_dp[multiple] = (new_dp[multiple] + dp[x]) % MOD;
            }
        }
        dp = new_dp;
    }

    int result = 0;
    for (int x = 1; x <= maxValue; x++) {
        result = (result + dp[x]) % MOD;
    }

    return result;
}
    int idealArrays(int n, int maxValue) {
        return countIdealArrays(n,maxValue);
    }
};