//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
         int n=s.length();
             
        vector<int>mp(26,-1);
    //    vector<int>result;
        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            mp[idx]=i;
        }
        int count=0;
        int i=0;
        while(i<n){
            int end = mp[s[i]-'a'];
            int j=i;
            while(j<end){
                end = max(end,mp[s[j]-'a']);
                j++;
            }
          count++;
            i=j+1;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends