class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();
      // pivot index find kiye  
      int idx=-1;
      for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx = i;
            break;
        }
      }
      if(idx == -1){
        reverse(nums.begin(),nums.end());
        return;
      }
      // pivot ke aage ka element ko reverse kar do
      reverse(nums.begin()+(idx+1),nums.end());
       
      //pivot element se just greater element khogna hai 
       int j= -1;
       for(int i= idx+1;i<n;i++){
          if(nums[i]>nums[idx]){
            j=i;
            break;
          }
       }
       //swap kar do idx element ko j wale element se 
       swap(nums[idx],nums[j]);
       return;
    }
};