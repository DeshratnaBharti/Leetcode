//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(string &s,int i,int j){
        if(i>=j) return true;
        if(s[i]==s[j]) return solve(s,i+1,j-1);
        return false;
    }
    string longestPalindrome(string &s) {
       int n =s.length();
       int maxLen = INT_MIN;
       int sp =0;
       for(int i=0;i<n;i++){
           for(int j =i;j<n;j++){
               if(solve(s,i,j)==true){
                   if(j-i+1 >maxLen){
                       maxLen = j-i+1;
                       sp=i;
                   }
               }
           }
       }
       return s.substr(sp,maxLen);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends