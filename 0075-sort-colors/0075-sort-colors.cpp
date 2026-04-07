class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,mid=0,h = nums.size()-1;
        while(mid<=h){
           // int mid = (l+h)/2;
            if(nums[mid]==1) mid++;
            else if(nums[mid] ==0){
                swap(nums[mid],nums[l]);
                l++,mid++;
            }
            else{
                swap(nums[mid],nums[h]);
                h--;
            }
        }
        
    }
};