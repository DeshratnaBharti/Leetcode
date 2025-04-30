class Solution {
public:
   bool isValid(int n){
    int count=0;
    while(n){
        n=n/10;
        count++;
    }
    return count%2==0?true:false;
   }
    int findNumbers(vector<int>& nums) {
        int even=0;
        for(int i=0;i<nums.size();i++){
            if(isValid(nums[i]))even++;
        }
        return even;
    }
};