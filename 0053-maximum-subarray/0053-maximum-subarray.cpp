class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0;
        int n= nums.size();
        int maxi =INT_MIN;
        for(int i=0;i<n;i++){
            s= s+nums[i];
            if(s>maxi){
                maxi = s;
            }
            if(s<0) s=0;
        }
        return maxi;
        
    }
};