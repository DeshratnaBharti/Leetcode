//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int m,n;
    int t[1001][1001];
    int f(string& s1,string& s2,int i,int j){
        if(i==m) return n-j;
       else if(j==n) return m-i;
        if(t[i][j] != -1) return t[i][j];
        if(s1[i]==s2[j] ) return t[i][j] = f(s1,s2,i+1,j+1);
        else{
            int insertC = 1+f(s1,s2,i,j+1);
            int deleteC = 1+f(s1,s2,i+1,j);
            int replaceC = 1+f(s1,s2,i+1,j+1);
            return t[i][j] = min({insertC,deleteC,replaceC});
            
        }
        return -1;
    }
    int editDistance(string& s1, string& s2) {
         m =s1.length();
         n =s2.length();
        memset(t,-1,sizeof(t));
        return f(s1,s2,0,0);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends