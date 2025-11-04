class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int cnt =0;
        int n = nums.size();
        for(int num:nums){
            if(num!=0) cnt++;
        }
        if(cnt<2) return 0;
        sort(nums.begin(),nums.end());
        long long maxi = 1,pd1 =1,pd2 = 1,pd3 =1;
        pd1 = pd1 *nums[n-1]*nums[n-2];
        pd1 = abs(pd1);
        pd2 = pd2 * nums[0]*nums[n-1];
        pd2 = abs(pd2);
        pd3 = pd3 *nums[0]*nums[1];
        pd3 = abs(pd3);
        maxi = max({pd1,pd2,pd3});
        return maxi*100000;
    }
};