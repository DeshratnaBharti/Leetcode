class Solution {
public:
    int countSubarrays(vector<int>& nums) {
      
       int n= nums.size();
       int count=0;
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j-i+1==3 and nums[j]+nums[i]==nums[i+1]/2)count++;
        }
       }
       return count;
    }
};