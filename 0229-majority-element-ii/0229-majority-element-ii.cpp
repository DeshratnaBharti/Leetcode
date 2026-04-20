class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 =0,c2 =0;
        int maj1 = NULL,maj2 = NULL;
        for(int i=0;i<n;i++){
            if(nums[i] == maj1) c1++;
            else if(nums[i]==maj2) c2++;
            else if(maj1 ==0){
                maj1 = nums[i];
                c1++;

            }else if(maj2 ==0){
                maj2 = nums[i];
                c2++;
            }else {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto a:nums){
            if(a ==maj1)c1++;
            if(a == maj2)c2++;
        }
        vector<int>ans;
        if(c1>n/3) ans.push_back(maj1);
        if(c2>n/3) ans.push_back(maj2);
        return ans;
    }
};