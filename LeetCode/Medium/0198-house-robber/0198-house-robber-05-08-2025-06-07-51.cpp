class Solution {
public:
    int n;
   vector<int>dp;
    int f(vector<int>&nums,int i){
         if(i>=nums.size()) return 0;
       //  if(i==nums.size()-2) return max(nums[i],nums[i+1]);
         if(dp[i]!=-1) return dp[i];
        int take =nums[i]+ f(nums,i+2);
        int not_Take = f(nums,i+1);
        return dp[i]=max(take,not_Take);
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        n=nums.size();
        return f(nums,0);
    }
};