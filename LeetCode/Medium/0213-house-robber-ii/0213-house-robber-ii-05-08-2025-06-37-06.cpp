class Solution {
public:
    vector<int> dp;
    
    int f(vector<int>& nums, int i, int n) {
        if (i > n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int take = nums[i] + f(nums, i + 2, n);
        int notTake = f(nums, i + 1, n);
        
        return dp[i] = max(take, notTake);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // Handle single-element case
        
        dp.assign(n, -1);
        int case1 = f(nums, 0, n - 2);  // Consider excluding last house
        dp.assign(n, -1);
        int case2 = f(nums, 1, n - 1);  // Consider excluding first house
        
        return max(case1, case2);
    }
};
