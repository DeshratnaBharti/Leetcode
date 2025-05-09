//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points) {
        // Code here
        int n=points.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));

    // Initialize the first day's merit points
    for (int j = 0; j < 3; j++) {
        dp[0][j] = points[0][j];
    }

    // Iteratively fill the DP table for each day
    for (int i = 1; i < n; i++) {
        dp[i][0] = points[i][0] + max(dp[i-1][1], dp[i-1][2]); // Running
        dp[i][1] = points[i][1] + max(dp[i-1][0], dp[i-1][2]); // Fighting
        dp[i][2] = points[i][2] + max(dp[i-1][0], dp[i-1][1]); // Learning Moves
    }

    // Return the maximum merit points possible on the last day
    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends