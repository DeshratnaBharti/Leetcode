class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0); // dp[i] = number of people who learn the secret on day i
        dp[1] = 1;

        int shareable = 0; // number of people who can share the secret on day i

        for (int day = 2; day <= n; day++) {
            // Add people who start sharing today
            if (day - delay >= 1)
                shareable = (shareable + dp[day - delay]) % MOD;
            // Remove people who forget today
            if (day - forget >= 1)
                shareable = (shareable - dp[day - forget] + MOD) % MOD;

            dp[day] = shareable;
        }

        // Count people who still remember the secret at the end
        int result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            result = (result + dp[day]) % MOD;
        }

        return result;
    }
};
