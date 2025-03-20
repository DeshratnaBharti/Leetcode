//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    
int t[100001][3][2]; // Updated size to handle larger constraints (prices.size() <= 10^5)
int n; // Global variable to store the size of the prices array

int f(int ind, int mode, int k, vector<int>& arr) {
    if (ind == n) return 0; // Base case: reached the end of the array
    if (k == 0) return 0;   // Base case: no transactions left
    if (t[ind][k][mode] != -1) // If already computed
        return t[ind][k][mode];
    
    if (mode == 0) { // Buy mode
        int buy = f(ind + 1, 1, k, arr) - arr[ind]; // Buy the stock
        int skip = f(ind + 1, 0, k, arr);          // Skip this stock
        t[ind][k][mode] = max(buy, skip);
    } else { // Sell mode
        int sell = f(ind + 1, 0, k - 1, arr) + arr[ind]; // Sell the stock
        int skip = f(ind + 1, 1, k, arr);               // Skip this stock
        t[ind][k][mode] = max(sell, skip);
    }
    return t[ind][k][mode];
}
    int maxProfit(vector<int> &arr) {
        // code here
        // code here
        memset(t, -1, sizeof(t)); // Initialize the DP array with -1
    n = arr.size();
    return f(0, 0, 2, arr); // Start with 0th index, buy mode, and 2 transactions allowed
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends