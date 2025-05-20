class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        // Apply each query
        for (auto& query : queries) {
            int s = query[0];
            int e = query[1];

            // Ensure indices are within range
            if (s < 0 || e >= n) continue;

            for (int i = s; i <= e; i++) {
                nums[i] = max(0, nums[i] - 1); // Avoid negative values
            }
        }

        // Check if array is zero
        return all_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
    }
};
