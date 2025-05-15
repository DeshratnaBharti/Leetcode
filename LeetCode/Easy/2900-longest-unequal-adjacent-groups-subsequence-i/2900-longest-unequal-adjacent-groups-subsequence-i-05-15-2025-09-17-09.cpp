class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n= groups.size();
        vector<string>ans(n);
        ans.push_back(words[0]);
        if(n==1) return words;
        for(int i=1;i<n;i++){
            if(groups[i]!=groups[i-1]){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};