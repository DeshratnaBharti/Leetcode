class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int resultP = nums[0];
        int  maxP = resultP;
        int  minP =resultP;
        
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] <0){
                swap(maxP,minP);
                
            }
            maxP = max(nums[i],maxP*nums[i]);
            minP = min(nums[i],minP*nums[i]);
            resultP = max(resultP,maxP);
        }
        return resultP;
    }
};