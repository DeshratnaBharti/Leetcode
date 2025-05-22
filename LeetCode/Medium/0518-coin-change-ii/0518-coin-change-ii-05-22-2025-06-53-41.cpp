class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int f(int amount, vector<int>& coins, int i, int s) {
        if (s == amount) return 1;
        if (i == n || s > amount) return 0;

        if (dp[i][s] != -1) return dp[i][s];

        int take = f(amount, coins, i, s + coins[i]); 
        int not_take = f(amount, coins, i + 1, s); 

        return dp[i][s] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1)); 
        return f(amount, coins, 0, 0);
    }
};
