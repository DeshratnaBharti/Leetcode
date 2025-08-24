class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int countZero=0;
        for(auto a:nums){
            if(a==0) countZero++;
        }
        if(countZero==0) return n-1;
        int i=0,j=0;
        int result=0;
        int last_zero=-1;
        while(j<n){
             
             if(nums[j]==0){
               i = last_zero+1;
               last_zero=j;
             }
             result = max(result,j-i);
             j++;
        }
        return result;
    }
};