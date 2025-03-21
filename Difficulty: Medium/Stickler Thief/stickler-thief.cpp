//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public: 
    int n;
    int t[100001];
    int f(vector<int>&arr,int i){
        if(i>=n) return 0;
        if(t[i]!=-1)return t[i];
        int steal = arr[i]+ f(arr,i+2);
        int notSteal = f(arr,i+1);
        return t[i]=max(steal,notSteal);
        
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        memset(t,-1,sizeof(t));
        n = arr.size();
        return f(arr,0);
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

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends