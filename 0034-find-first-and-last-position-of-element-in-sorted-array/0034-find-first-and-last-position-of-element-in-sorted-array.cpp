class Solution {
public:
    int findrightmost(vector<int>& nums, int target,int n){
        int low=0,high=n-1;
        int right_most=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                right_most =mid;
                low=mid+1;

            }else if(nums[mid]<target)low = mid +1;
            else high = mid-1;
        }
        return right_most;
    }
    int findleftmost(vector<int>& nums, int target,int n){
        int low=0,high=n-1;
        int left_most=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                left_most =mid;
                high=mid-1;

            }else if(nums[mid]<target)low = mid +1;
            else high = mid-1;
        }
        return left_most;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        int left_ones=findleftmost(nums,target,n);
        int right_ones= findrightmost(nums,target,n);
        return {left_ones,right_ones};
    }
};