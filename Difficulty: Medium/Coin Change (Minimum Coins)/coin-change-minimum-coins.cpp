//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  int n;
   int dp[10001][101]; // DP table
   int f(vector<int>& coins, int sum, int i) {
    // Base cases
    if (sum == 0) return 0;        // If sum becomes 0, no more coins are needed
    if (sum < 0 || i == coins.size()) return INT_MAX; // Invalid case

    // Recursive cases
    int take = INT_MAX, notTake;
    if (dp[sum][i] != -1) return dp[sum][i];
    if (sum >= coins[i]) {
        int res = f(coins, sum - coins[i], i); // Try taking the current coin
        if (res != INT_MAX) take = 1 + res;   // Only add 1 if the result is valid
    }
    notTake = f(coins, sum, i + 1);           // Try skipping the current coin

    return dp[sum][i] = min(take, notTake); // Return the minimum coins needed
}

    int minCoins(vector<int> &coins, int sum) {
        // code here
        n = coins.size();
          memset(dp, -1, sizeof(dp)); // Initialize the DP table with -1
        int result = f(coins, sum, 0);
        return result == INT_MAX ? -1 : result;
    }
};




//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends