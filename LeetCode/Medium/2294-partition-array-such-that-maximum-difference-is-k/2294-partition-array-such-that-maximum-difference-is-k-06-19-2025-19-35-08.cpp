class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minVal = nums[0];
        int count=1;
        for(int i=0;i<n;i++){
            if((nums[i]-minVal)>k){
               count++;
               minVal=nums[i];
            }
        }

        return count;
    }
};