class Solution {
public:
    int n;
    bool isPalindrome(string s,int idx,int i){
        while(idx < i){
            if(s[idx] != s[i]) return false;
            idx++,i--;
        }
        return true;
    }
    void solve(string &s,int idx,vector<string>& temp,vector<vector<string> >&result){
        if(idx ==n ){
            result.push_back(temp);
            return;
            
        }
        for(int i = idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,temp,result);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
         n = s.length();
        vector<vector<string> >result;
        vector<string> temp;
      
        solve(s,0,temp,result);
        return result;
            
    }
};