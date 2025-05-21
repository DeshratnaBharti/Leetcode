class Solution {
public:
   int n;
    int f(vector<int>nums,int i,int target,int sum){
        if(i==n){
            if(sum==target) return 1;
            else return 0;
        }
        int plus = f(nums,i+1,target,sum+nums[i]);
        int minus = f(nums,i+1,target,sum-nums[i]);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n= nums.size();
        return f(nums,0,target,0);
    }
};