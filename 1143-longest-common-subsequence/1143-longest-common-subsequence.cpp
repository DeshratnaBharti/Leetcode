class Solution {
public:
    int m,n;
    int solve(string& s1,string& s2,int i,int j){
        if(i>=m or j>=n) return 0;
        if(s1[i]==s2[j]) return 1+solve(s1,s2,i+1,j+1);
        int a = solve(s1,s2,i+1,j);
        int b = solve(s1,s2,i,j+1);
        return max(a,b);
    }
    int longestCommonSubsequence(string s1, string s2) {
       m = s1.length();
       n = s2.length();
       return solve(s1,s2,0,0); 
    }
};