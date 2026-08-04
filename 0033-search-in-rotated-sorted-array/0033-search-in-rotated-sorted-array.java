class Solution {
    public int search(int[] nums, int tgt) {
        int n = nums.length;
        int l=0,h=n-1;
        while(l<=h){
           int mid = (l + h)/2;
           if(nums[mid] == tgt) return mid;
          else if(nums[l]<=nums[mid]){
            if (tgt >= nums[l] && tgt < nums[mid]) h=mid-1;
            else l= mid+1;
           } else{
            if(nums[mid] < tgt && nums[h]>=tgt) l = mid +1;
            else h = mid -1;
           }
        }
        return -1;
    }
    
}