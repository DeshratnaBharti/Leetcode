//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int t[101][101];
     int f(int start,int end,vector<int>&arr){
         if(end-start==1) return 0;
         int ans = INT_MAX;
         if(t[start][end] != -1) return t[start][end];
         for(int k= start+1;k<end;k++){
             int left = f(start,k,arr);
             int right = f(k,end,arr);
             ans = min(ans,left+right+arr[start]*arr[k]*arr[end]);
             
         }
         return t[start][end]= ans;
     }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        memset(t,-1,sizeof(t));
        return f(0,n-1,arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends