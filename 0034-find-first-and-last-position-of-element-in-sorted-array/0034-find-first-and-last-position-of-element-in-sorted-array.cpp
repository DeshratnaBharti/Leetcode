class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int lb = -1,ub =-1;
        int n = nums.size();
        int i =0,j =n-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==t){
               lb = mid ;
              
               j= mid -1;
             
            }else if(nums[mid] >t){
                j= mid -1;
            }else {
                i= mid +1;
            }

        }
         i =0,j =n-1;
         while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==t){
              
               ub= mid ;
             
              i= mid+1;
            }else if(nums[mid] >t){
                j= mid -1;
            }else {
                i= mid +1;
            }

        }
        return {lb,ub};
    }
};