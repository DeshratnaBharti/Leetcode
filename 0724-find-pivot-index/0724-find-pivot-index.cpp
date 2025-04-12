class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0,leftSum=0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        for(int i=0;i<n;i++){
            int rightS = totalSum - leftSum-nums[i];
            if(rightS ==leftSum) return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};