class Solution {
public:
     int n;
     int t[2501][2501];
    int f(vector<int>& nums,int i,int prevIn){
        if(i>=n) return 0;
        int take=0;
        if(t[i][prevIn+1]!=-1) return t[i][prevIn+1];
        if(prevIn==-1 or nums[prevIn]<nums[i]){
             take = 1+f(nums,i+1,i);
        }
        int notTake = f(nums,i+1,prevIn);
        return t[i][prevIn+1]= max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
         n= nums.size();
        return f(nums,0,-1);
        
    }
};