class Solution {
public:
    int m,n;
   int t[501][501];
    int f(string &s1,string &s2,int  i ,int  j){
        if(i==m) return n-j;
        else if(j==n) return m-i;
        if(t[i][j]!=-1) return t[i][j];
        if(s1[i]==s2[j]) return t[i][j]= f(s1,s2,i+1,j+1);
        else {
            int ins = 1+ f(s1,s2,i,j+1);
            int del = 1+ f(s1,s2,i+1,j);
            int rep = 1+ f(s1,s2,i+1,j+1);

            return t[i][j]= min({ins,del,rep});
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        m = s1.length();
     n = s2.length();
     memset(t,-1,sizeof(t));
        return f(s1,s2,0,0);
    }
};