// User function template for C++

class Solution {
  public:
    int m,n;
    vector<vector<int>> t;
    // Function to find length of shortest common supersequence of two strings.
    int f(string &s1,string& s2, int m,int n){
        if(n==0 or m==0) return m+n;
        if(t[m][n]!=-1) return t[m][n];
        if(s1[m-1]==s2[n-1]) return t[m][n]=1 + f(s1,s2,m-1,n-1);
        else return t[m][n]=1 + min(f(s1,s2,m-1,n),f(s1,s2,m,n-1));
        return 0;
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        m = s1.length();
        n = s2.length();
         t.assign(m + 1, vector<int>(n + 1, -1));
        return f(s1,s2,m,n);
    }
};