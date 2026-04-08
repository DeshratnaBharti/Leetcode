class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a :nums){
            mp[a]++;
        }
        for(auto a:mp){
            int b = a.first;
            int c = a.second;
            if(c>1) return b;
        }
        return -1;
    }
};