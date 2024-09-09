class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int count =0;
        int maxCount =1;
        int prevSmaller = INT_MIN;
        for(int i=0;i<n;i++){
            if( nums[i] -1 == prevSmaller){
                count += 1;
                prevSmaller = nums[i];
            }
            else if( nums[i] != prevSmaller){  
                   count =1;
                   prevSmaller =nums[i];
                
            }
            maxCount = max(maxCount,count);
        }
        
        return  maxCount;
    }
};