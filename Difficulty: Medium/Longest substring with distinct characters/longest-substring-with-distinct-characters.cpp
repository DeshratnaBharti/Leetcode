class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int>mp;
        int n = s.length();
        int i=0,j=0;
        int maxi = INT_MIN;
        while(j<n){
            char ch = s[j];
            while(mp.count(ch)){
               mp[s[i]]--;
               if(mp[s[i]]==0) mp.erase(s[i]);
                 i++;
              }
              mp[ch]++;
              maxi = max(maxi,j-i+1);
              j++;
        
        }
        return maxi;
    }
};
