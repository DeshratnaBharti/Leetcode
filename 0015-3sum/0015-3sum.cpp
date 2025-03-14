class Solution {
public:
 vector<vector<int>> result;
 void twosum(vector<int>& nums,int tgt,int j, int k){
    while(j<k){
        if(nums[j]+nums[k]> tgt)k--;
        else  if(nums[j]+nums[k]<tgt) j++;
        else{
            while(j<k and nums[j]==nums[j+1]) j++;
             while(j<k and nums[k]==nums[k-1]) k--;
             result.push_back({-tgt,nums[j],nums[k]});
             j++; k--;
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