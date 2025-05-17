//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:

        // Your code goes here
        int helper(vector<int>& arr, int n, int currSum, vector<vector<int>>& dp) {
    if (n == 0) return currSum == 0 ? 1 : 0;
    if (dp[n][currSum] != -1) return dp[n][currSum];

    // Exclude current element
    bool exclude = helper(arr, n - 1, currSum, dp);

    // Include current element if it doesn't exceed currSum
    bool include = false;
    if (arr[n - 1] <= currSum)
        include = helper(arr, n - 1, currSum - arr[n - 1], dp);

    return dp[n][currSum] = include || exclude;
}

int minDifference(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(totalSum / 2 + 1, -1));

    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (helper(arr, n, s1, dp)) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }

    return minDiff;
}

    
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int ans = ob.minDifference(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends