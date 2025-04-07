class Solution {
public:
    int n;
    int t[201][101];
    bool help(vector<int>& nums,int s,int i){
        
        if (s == 0) return true; // Base case: subset with required sum found
        if (i == n || s < 0) return false;
        if(t[i][s] != -1) return t[i][s];
        bool take,not_take;
       
         take = help(nums,s-nums[i],i+1);
         not_take = help(nums,s,i+1);
        
        return t[i][s]=take or not_take;
    }
    bool canPartition(vector<int>& nums) {
         n =nums.size();
        int sum=0;
        memset(t,-1,sizeof(t));
        for(auto &num:nums){
            sum+=num;
        }
        if(sum %2 != 0) return false;
        return help(nums,sum/2,0);
    }
};