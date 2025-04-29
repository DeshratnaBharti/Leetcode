class Solution {
public:  
    bool isValid(vector<int>& nums, int start, int end, int k, int maxElement) {
        int count = 0;

        // Count occurrences of maxElement in the subarray
        for (int i = start; i <= end; i++) {
            if (nums[i] == maxElement) {
                count++;
            }
        }

        return count >= k; // Check if maxElement appears at least k times
    }

    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        // Iterate through all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isValid(nums, i, j, k, maxElement)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

