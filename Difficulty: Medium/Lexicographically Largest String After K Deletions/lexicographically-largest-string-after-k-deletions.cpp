class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.length();
        // code here
        string ans ="";
        for(int i=0;i<n;i++){
            while(!ans.empty()and ans.back()<s[i] and k>0){
                ans.pop_back();
                k--;
            }
            ans.push_back(s[i]);
        }
        while( k>0){
                ans.pop_back();
                k--;
            }
            return ans;
        
    }
};
