class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
         mp.insert({0,1});
        int s=0,count=0;
        for(auto &a:nums){
             s += a;
            if( mp.find(s-k) != mp.end()){
                count += mp[s-k];
            }
            mp[s]++;

        }
        return count;
        
    }
};