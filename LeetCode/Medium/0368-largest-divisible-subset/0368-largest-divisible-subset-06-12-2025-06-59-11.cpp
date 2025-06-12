class Solution {
public:
    vector<vector<vector<int>>> dp;

    vector<int> f(int idx, vector<int>& nums, int prevIdx) {
        if (idx == nums.size()) return {};

        if (dp[idx][prevIdx + 1].size() != 0) {
            return dp[idx][prevIdx + 1];
        }

        vector<int> take;
        if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0) {
            take = f(idx + 1, nums, idx);
            take.insert(take.begin(), nums[idx]);
        }

        vector<int> notTake = f(idx + 1, nums, prevIdx);

        if (take.size() > notTake.size()) {
            dp[idx][prevIdx + 1] = take;
        } else {
            dp[idx][prevIdx + 1] = notTake;
        }

        return dp[idx][prevIdx + 1];
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // prevIdx + 1 to handle -1 case
        dp.assign(n, vector<vector<int>>(n + 1, vector<int>()));
        return f(0, nums, -1);
    }
};
