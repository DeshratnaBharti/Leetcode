class Solution {
public:
    bool search(vector<int>& nums, int k) {
         int n= nums.size();
        int low =0;
        int high = n-1;
        while(low <= high){
            int mid = low+(high -low)/2;
             if(nums[mid] ==k) return true;
             if(  nums[low] == nums[mid] and nums[mid] == nums[high]){
                 low= low+1;
                high = high -1;
                continue;
            }
         else   if(nums[low] <= nums[mid]){
                if(nums[low] <= k and k<= nums[mid]){
                    high = mid -1;
                    
                }else low =mid +1;
            }
           
            else {
                if(nums[mid] <= k and k <= nums[high]){
                    low =  mid+1;
                    
                }else{
                     high = mid-1;
                }
            }
        }
        return false;
        
    }
};