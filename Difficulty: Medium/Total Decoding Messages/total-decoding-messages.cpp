//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int t[1001];
    int helper(int i,int n,string& s){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(t[i] != -1) return t[i];
        int ans =0;
        ans += helper(i+1,n,s);
        if(i<n-1){
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num<= 26){
                ans+=helper(i+2,n,s);
            }
        }
        return t[i]=ans;
    }
    int countWays(string &digits) {
        // Code here
        memset(t,-1,sizeof(t));
        int n = digits.length();
        return helper(0,n,digits);
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends