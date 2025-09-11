class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low =0,mid =0,last =n-1;
        while(mid<=last){
            if(nums[mid]==1) mid++;
            else if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++,mid++;

            }else{
                swap(nums[mid],nums[last]);
                last--;
            }
        }
        
    }
};