class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2){
            int x = nums[i-1]^nums[i];
            if(x!=0) return false;
        }
        return true;
    }
};