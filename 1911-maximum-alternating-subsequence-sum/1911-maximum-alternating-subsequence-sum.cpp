class Solution {
public:
    int n;
    vector<vector<long long>>dp;
    long long solve(vector<int>&nums,int i,int flag){
        if(i>=n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        long long not_take = solve(nums,i+1,flag);
        long long val = nums[i];
        if(flag == false){
            val = - val;
        }
        long long take = solve(nums,i+1,!flag)+val;
        return dp[i][flag]= max(take,not_take);

    }
    long long maxAlternatingSum(vector<int>& nums) {
         n = nums.size();
         dp.resize(n+1,vector<long long>(2,-1));
        return solve(nums,0,true);
    }
};