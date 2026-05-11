class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool solve(vector<int>&nums,int i,int sum,int tgt){
        if(i>=n or sum>tgt) return false;
        if(sum==tgt ) return true;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = solve(nums,i+1,sum + nums[i],tgt);
        bool skip = solve(nums,i+1,sum,tgt);
        return dp[i][sum]=take or skip ;


    }
    bool canPartition(vector<int>& nums) {
        n = nums.size(); 
         
        int s= accumulate(nums.begin(),nums.end(),0);
        if(s%2 !=0) return false;
        int tgt = s/2;
        dp.resize(n,vector<int>(tgt+1,-1));
        return solve(nums,0,0,tgt);
    }
};