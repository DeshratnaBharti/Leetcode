class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low =0;
        int high = n-1;
        int minE = INT_MAX;
       while(low <= high){
            int mid = low+(high -low)/2;
        //     if(nums[mid] >= minE) minE = nums[mid];
         if(nums[low] <= nums[mid]){//left wala sorted
                minE = min(minE,nums[low]);
                low = mid+1;
            }
           //right wala sorted
            else {
               // if(nums[mid]  <= nums[high]){
                     minE = min(minE,nums[mid]);
                  high = mid-1;
                    
            }
       }
        return minE;
    }
};