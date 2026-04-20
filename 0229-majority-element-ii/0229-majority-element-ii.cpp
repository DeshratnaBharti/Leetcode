class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 =0,c2 =0;
        int maj1 = INT_MIN,maj2 = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] == maj1) c1++;
            else if(nums[i]==maj2) c2++;
            else if(c1==0){
                maj1 = nums[i];
                c1=1;

            }else if(c2==0){
                maj2 = nums[i];
                c2=1;
            }else {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto a:nums){
            if(a ==maj1)c1++;
            else if(a == maj2)c2++;
        }

        vector<int>ans;
        if(c1> n/3) ans.push_back(maj1);
        if(c2> n/3) ans.push_back(maj2);
       // if(c1==c2) return {maj1};
        return ans;
    }
};