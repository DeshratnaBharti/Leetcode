//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: If the knapsack has no capacity or no items left, return 0
    if (ind == 0 || W == 0) {
        return 0;
    }

    // Return the precomputed result if available
    if (dp[ind][W] != -1) {
        return dp[ind][W];
    }

    // Exclude the current item
    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);

    // Include the current item if it fits
    int taken = (wt[ind - 1] <= W) ? val[ind - 1] + knapsackUtil(wt, val, ind - 1, W - wt[ind - 1], dp) : 0;

    // Store and return the optimal result
    dp[ind][W] = max(notTaken, taken);
    return dp[ind][W];
}

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    
    // Initialize the DP table with dimensions (n+1) x (W+1) and fill it with -1
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    
    // Call the helper function
    return knapsackUtil(wt, val, n, W, dp);
}
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends