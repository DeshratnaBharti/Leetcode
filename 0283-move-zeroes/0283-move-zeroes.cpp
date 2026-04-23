class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int i=0,j=0;
         while(j<n){
              while( j<n and nums[j] ==0)j++;
              while(i<n and nums[i] != 0) i++;
              if(j<n and i<j and i<n){
               swap(nums[i],nums[j]);
               i++;
              }
              j++;
         }
    }
};