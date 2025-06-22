class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string>ans;
        for(int i=0;i<n;i+=k){
           ans.push_back(s.substr(i,k));
        }
         string lastword = ans.back();
         if(lastword.length()<k){
            ans.pop_back();
            while(lastword.length()!=k) lastword += fill;
             ans.push_back(lastword);
         }
       //   ans.push_back(lastword);
          return ans;
    }
};