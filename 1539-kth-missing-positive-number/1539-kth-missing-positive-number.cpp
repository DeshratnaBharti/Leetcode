class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0; int high = n-1;
        int mid =-1;
        while (low <= high){
            mid = low + (high - low)/2;
            int midtak_kitnemissing = nums[mid] -(mid+1);
            if(midtak_kitnemissing <k){
                low = mid +1;
                
            }else{
                high =mid -1;
            }
        }
        return low+k;
    }
};