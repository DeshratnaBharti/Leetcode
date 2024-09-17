class Solution {
public:
 vector<vector<int>> result;
 void twosum(vector<int>& nums,int tgt,int i, int j){
    while(i<j){
        if(nums[i]+nums[j]> tgt)j--;
        else  if(nums[i]+nums[j]<tgt) i++;
        else{
            while(i<j and nums[i]==nums[i+1]) i++;
             while(i<j and nums[j]==nums[j-1]) j--;
             result.push_back({-tgt,nums[i],nums[j]});
             i++; j--;
        }
    }
 }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return {};
        result.clear();
        sort(nums.begin(),nums.end());
         //ek element ko fix kar do
         for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int n1 = nums[i];
            int target =-n1;
            twosum(nums,target,i+1,n-1);
         }
        return result;
    }
};