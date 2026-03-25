class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int s1 =0,s2=0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x<=9) s1= s1 + x;
            else s2 = s2 +x;
        }
        if(s1 > s2 or s2>s1) return true;
        return false;
        
    }
};