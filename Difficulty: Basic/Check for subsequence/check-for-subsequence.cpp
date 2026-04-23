
class Solution {
  public:
    bool isSubSequence(string s1, string s2) {
        // code here
        int m = s1.length();
        int n = s2.length();
        int i=0,j=0;
        while(i<m and j<n){
            if(s1[i] != s2[j]) j++;
            if(s1[i] == s2[j]){
                i++,j++;
            }
        }
        if(i==m ) return true;
        return false;
    }
};