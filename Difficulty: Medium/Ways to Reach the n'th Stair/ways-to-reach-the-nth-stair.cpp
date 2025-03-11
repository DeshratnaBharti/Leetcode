//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int t[45];
    int f(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        if(t[n] != -1) return t[n];
        int takeOne = f(n-1);
        int takeTwo = f(n-2);
        return t[n]=takeOne +takeTwo;
    }
    int countWays(int n) {
        // your code here
        memset(t,-1,sizeof(t));
        return f(n);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends