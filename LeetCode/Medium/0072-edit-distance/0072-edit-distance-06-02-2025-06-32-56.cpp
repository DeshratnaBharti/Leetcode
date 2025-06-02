class Solution {
public:
    int m,n;
    int f(string &s1,string &s2,int  i ,int  j){
        if(i==m) return n-j;
        else if(j==n) return m-i;
        if(s1[i]==s2[j]) return f(s1,s2,i+1,j+1);
        else {
            int ins = 1+ f(s1,s2,i,j+1);
            int del = 1+ f(s1,s2,i+1,j);
            int rep = 1+ f(s1,s2,i+1,j+1);

            return min({ins,del,rep});
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        m = s1.length();
     n = s2.length();
        return f(s1,s2,0,0);
    }
};