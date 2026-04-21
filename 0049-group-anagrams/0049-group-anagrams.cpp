class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>v;
        for(int i=0;i<n;i++){
            string t = strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(strs[i]);


        }
        for(auto a:mp){
            
            v.push_back(a.second);
        }
        return v;
        
    }
};