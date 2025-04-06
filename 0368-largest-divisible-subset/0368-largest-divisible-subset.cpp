class Solution {
public:
    void generate(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
        if(idx >= nums.size()) {
            if(temp.size() > result.size()) {
                result = temp;
            }
            return;
        }
        
        if(prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            generate(idx+1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }
        
        generate(idx+1, nums, result, temp, prev);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
           sort(begin(nums), end(nums));
        
        vector<int> result;
        vector<int> temp;
        generate(0, nums, result, temp, -1);
        
        return result;
    
    }
};