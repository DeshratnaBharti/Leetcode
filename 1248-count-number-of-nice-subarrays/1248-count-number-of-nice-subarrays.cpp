class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
       unordered_map<int,int>mp;
        int ans=0;
        int totalSum =0;
        mp.insert({0,1});
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i] %2;
            if((mp.find(totalSum - goal) != mp.end())){
                ans += mp[totalSum - goal];
            }
            mp[totalSum]++;
        }
        return ans;  
    }
};