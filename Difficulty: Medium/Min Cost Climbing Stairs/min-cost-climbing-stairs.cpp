//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
   int n;
   int t[100001];
   int f(int idx,vector<int>&cost){
       if(idx>=n) return 0;
       if(t[idx] != -1) return t[idx];
       int a = cost[idx]+f(idx+1,cost);
       int b = cost[idx] + f(idx+2,cost);
       return t[idx]=min(a,b);
   }
    int minCostClimbingStairs(vector<int>& cost) {
       n = cost.size();
       memset(t,-1,sizeof(t));
       return min(f(0,cost),f(1,cost));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends