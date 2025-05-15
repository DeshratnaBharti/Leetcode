//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  //top down approach
  int t[10001][201];
  int n;
    bool f(vector<int>& arr, int sum,int idx){
        if(sum==0) return true;
        if(idx==n) return false;
        if(t[sum][idx]!=-1) return t[sum][idx];
        bool take = false,notTake = false;
        if(arr[idx]<=sum) take = f(arr,sum-arr[idx],idx+1);
        notTake = f(arr,sum,idx+1);
        return t[sum][idx]= take or notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        n = arr.size();
        memset(t,-1,sizeof(t));
        return f(arr,sum,0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends