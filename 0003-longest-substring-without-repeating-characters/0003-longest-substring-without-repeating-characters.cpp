class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        int j=0,maxi=0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            while(mp.count(ch)){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
            
               
           
            maxi = max(maxi, i - j + 1);
             mp[ch]++;
        }
        return maxi;
        
    }
};