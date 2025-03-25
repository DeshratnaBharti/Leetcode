//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  int t[101][101][2];
    bool evaluate(int b1,int b2,char op){
        if(op=='&'){
            return b1&b2;
        }
        else if(op=='|'){
            return b1|b2;
        }
        else return b1^b2;
    }
    int f(int start,int end,int req,string &s){
        if(start==end){
            return (req==(s[start]=='T')) ? 1:0;
        }
        if(t[start][end][req] != -1) return t[start][end][req];
        int ans =0;
        for(int k = start+1;k<end;k++){
            int lT= f(start,k-1,1,s);
            int lF = f(start,k-1,0,s);
            int rT = f(k+1,end,1,s);
            int rF = f(k+1,end,0,s);
            
            if(evaluate(1,1,s[k])==req){
                ans += lT*rT;
            }
            if(evaluate(1,0,s[k])==req){
                ans += lT*rF;
            }
            if(evaluate(0,1,s[k])==req){
                ans += lF*rT;
            }
            if(evaluate(0,0,s[k])==req){
                ans += lF*rF;
            }
        }
        return t[start][end][req] = ans;
    }
    int countWays(string &s) {
       int n = s.length();
       memset(t,-1,sizeof(t));
       return f(0,n-1,1,s);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends