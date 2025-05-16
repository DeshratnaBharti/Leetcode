class Solution {
public:
    int n;
    vector<vector<int>> t; // Use dynamic sizing for the memoization table
    
    bool help(vector<int>& nums, int s, int i) {
        if (s == 0) return true; // Base case: subset with required sum found
        if (i == n || s < 0) return false; // Base case: all elements processed or sum becomes negative
        if (t[i][s] != -1) return t[i][s]; // Return memoized result if already calculated
        
        // Recursive case: include or exclude the current element
        bool take = help(nums, s - nums[i], i + 1);
        bool not_take = help(nums, s, i + 1);
        
        return t[i][s] = (take || not_take); // Store result
    }
    
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        long long sum = 0; // Use long long to prevent overflow
        for (auto &num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false; // If total sum is odd, can't partition into two equal subsets
        
        int target = sum / 2; // Calculate the target sum
        t.resize(n, vector<int>(target + 1, -1)); // Dynamically size the memoization table
        
        return help(nums, target, 0);
    }
};
