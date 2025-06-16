class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
              int dif= nums[j]-nums[i];
              maxi = max(maxi,dif);
            }
          
          
        }
        return maxi;
    }
};