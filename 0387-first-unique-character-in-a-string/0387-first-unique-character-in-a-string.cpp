class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        for(auto ch : s){
            mp[ch]++;
        }
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(mp[ch] >1)continue;
            else {
                return i;
            }
        }
        return -1;
    }
};