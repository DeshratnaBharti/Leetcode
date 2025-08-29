class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
          unordered_map<string, vector<string>> umap;

      
        for (const string& s : arr) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); 
            umap[sorted_s].emplace_back(s);   
        }  
        vector<vector<string>> result;
        result.reserve(umap.size());              
        for (auto& [key, anagrams] : umap) {
            result.push_back(move(anagrams));     
        }

        return result;
    }
    
};