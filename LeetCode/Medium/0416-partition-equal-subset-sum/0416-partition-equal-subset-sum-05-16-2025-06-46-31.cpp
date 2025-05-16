class Solution {
public:
    int n;
    vector<vector<int>> t;
    
    bool help(vector<int>& nums, int s, int i) {
        if (s == 0) return true; 
        if (i == n || s < 0) return false; \
        if (t[i][s] != -1) return t[i][s];
        
       
        bool take = help(nums, s - nums[i], i + 1);
        bool not_take = help(nums, s, i + 1);
        
        return t[i][s] = (take || not_take); 
    }
    
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        long long sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false; 
        int target = sum / 2; 
        t.resize(n, vector<int>(target + 1, -1)); 
        
        return help(nums, target, 0);
    }
};
