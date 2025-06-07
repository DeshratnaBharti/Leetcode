class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
    int profit[k + 1][n + 1];
	for (int i = 0; i <= k; i++) {
	    profit[i][0] = 0;
	}
	for (int i = 0; i <= n; i++) {
		profit[0][i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j < n; j++) {
			int currMax = INT_MIN;
			for (int day = 0; day < j; day++) {
				currMax = max(currMax, prices[j] - prices[day] + profit[i - 1][day]);
			}
			profit[i][j] = max(profit[i][j - 1], currMax);
		}
	}
	return profit[k][n - 1];
    }
};