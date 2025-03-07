//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
   int t[1001][1001];
    int m;
    int solve(string& s1,string& s2,int i,int j){
        if(i==m or j==m) return t[i][j]= 0;
        if(t[i][j] != -1) return t[i][j];
        if(s1[i]==s2[j]) return t[i][j]=1+solve(s1,s2,i+1,j+1);
        else return t[i][j]= max(solve(s1,s2,i,j+1),solve(s1,s2,i+1,j));
    }
    int longestPalinSubseq(string &s1) {
        memset(t,-1,sizeof(t));
        string s2 = s1;
        reverse(s2.begin(),s2.end());
       m=s1.length();
       return solve(s1,s2,0,0);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends