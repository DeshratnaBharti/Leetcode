class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    void f(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
        if (idx >= nums.size()) {
            if (temp.size() > result.size()) {
                result = temp;
            }
            return;
        }

        // If already computed, return stored result
        if (dp[idx].size() > 0) {
            temp = dp[idx];
            return;
        }

        // Take option
        if (prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            f(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }

        f(idx + 1, nums, result, temp, prev);

        // Store the best result for this index
        dp[idx] = result;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<int> temp;
        int prev = -1;
        dp.assign(nums.size(), vector<int>()); // Initialize memoization table
        f(0, nums, result, temp, prev);
        return result;
    }
};
