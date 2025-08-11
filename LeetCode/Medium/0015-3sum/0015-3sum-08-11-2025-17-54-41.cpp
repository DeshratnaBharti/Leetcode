class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // If there are fewer than 3 elements, return an empty result
        if (n < 3) return result;

        // Sort the array to handle duplicates and enable two-pointer technique
        sort(nums.begin(), nums.end());

        // Iterate through the array, fixing one element at a time
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i]; // Target for two-sum
            int left = i + 1, right = n - 1;

            // Use the two-pointer technique to find pairs that sum to the target
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate elements for the second number
                    while (left < right && nums[left] == nums[left + 1]) left++;

                    // Skip duplicate elements for the third number
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};
