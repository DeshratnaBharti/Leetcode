class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto a:arr){
            mp[a]++;
        }
        unordered_set<int>s;
        for(auto a:mp){
            int b = a.second;
           s.insert(b);
        }
        return mp.size()==s.size();
        
    }
};