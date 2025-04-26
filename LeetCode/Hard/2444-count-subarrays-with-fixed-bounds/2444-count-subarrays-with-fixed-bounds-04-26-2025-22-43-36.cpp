class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
          long long ans = 0;
        int lastInvalid = -1, lastMinK = -1, lastMaxK = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) lastInvalid = i;
            if (nums[i] == minK) lastMinK = i;
            if (nums[i] == maxK) lastMaxK = i;

            ans += max(0, min(lastMinK, lastMaxK) - lastInvalid);
        }

        return ans;
    }
};