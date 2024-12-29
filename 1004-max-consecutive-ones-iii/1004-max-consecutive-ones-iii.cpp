class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int  i=0,j =0,n = nums.size();
        int noOfZeroinOneWin =0;
        int ans = INT_MIN;
        while(j<n){
            if(nums[j]==0) noOfZeroinOneWin++;
            while(noOfZeroinOneWin >k){
                if(nums[i]==0) noOfZeroinOneWin--;
                i++;
            }
            ans = max (ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};