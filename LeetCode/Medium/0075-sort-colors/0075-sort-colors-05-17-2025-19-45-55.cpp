class Solution {
public:
    void sortColors(vector<int>& nums) {
     int low=0;
     int mid=0;
     int last=nums.size()-1;
     while(mid<=last){
         if(nums[mid]==2){
             //swap(mid,last);
             int temp = nums[mid];
             nums[mid]=nums[last];
             nums[last]=temp;
             last--;
         }
         else if(nums[mid]==0){
             //swap(mid,low);
             int temp = nums[mid];
             nums[mid]=nums[low];
             nums[low]=temp;
             low++,mid++;
         }
         else mid++;
     }
     return;
    }
};