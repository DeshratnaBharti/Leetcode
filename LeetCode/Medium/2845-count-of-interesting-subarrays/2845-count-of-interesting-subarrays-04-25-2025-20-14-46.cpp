class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int x) {
        int n = nums.size();
        long long ans = 0;
        
        // To store the count of elements satisfying nums[k] % m == x
        vector<int> count(n + 1, 0); 
        
        // Create a prefix sum array where count[i] stores the number of elements satisfying the condition
        for (int i = 0; i < n; ++i) {
            count[i + 1] = count[i] + (nums[i] % m == x);
        }
        
        // For each ending point of the subarray, calculate valid subarrays ending at that point
        for (int j = 0; j < n; ++j) {
            // We want subarrays such that (count[j+1] - count[i]) % m == x
            // This condition is equivalent to (count[j+1] - x) % m == count[i] % m
            for (int i = 0; i <= j; ++i) {
                if ((count[j + 1] - x) % m == count[i] % m) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
