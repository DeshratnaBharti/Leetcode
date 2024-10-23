class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        
        int count =0;
        int maxm = 0;
         for(int i=0;i<n;i++){
             if(s[i]=='('){
                 count++;
             }else if(s[i] == ')'){
                 maxm = max(count,maxm);
                 count--;
             }
         }
        
        return maxm;
        
    }
};