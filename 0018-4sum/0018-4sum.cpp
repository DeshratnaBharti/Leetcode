class Solution {
public:
   vector<vector<int>> result;
 void twosum(vector<int>& nums,int n1,int n2,long long tgt,int i, int j){
    while(i<j){
        if(nums[i]+nums[j]> tgt)j--;
        else  if(nums[i]+nums[j]<tgt) i++;
        else{
            while(i<j and nums[i]==nums[i+1]) i++;
             while(i<j and nums[j]==nums[j-1]) j--;
             result.push_back({n1,n2,nums[i],nums[j]});
             i++; j--;
        }
    }
 }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n = nums.size();
        if(n<4) return {};
        result.clear();
        sort(nums.begin(),nums.end());
         //ek element ko fix kar do
         for(int i=0;i<n-3;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
              if(j>i+1 and nums[j ]== nums[j-1]) continue;
              long long n1 = nums[i];
              long long n2 = nums[j];
               long long tgt=  target-n1-n2;
              twosum(nums,n1,n2,tgt,j+1,n-1);
            }
         }
        return result;
    }
};