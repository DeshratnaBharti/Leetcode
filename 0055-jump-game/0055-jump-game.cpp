class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex =0;
        int i=0,n= nums.size();
        while(i<n){
            if(i>maxIndex) return false;
            maxIndex = max(maxIndex,i+nums[i]);
            i++;
        }
        return true;
    }
};