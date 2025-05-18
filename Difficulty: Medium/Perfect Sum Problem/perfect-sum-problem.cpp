//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
   // bottom up approach
    int perfectSum(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

     
        if (arr[0] == 0) {
            dp[0][0] = 2; 
        } else {
            dp[0][0] = 1;
            if (arr[0] <= target)
                dp[0][arr[0]] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int t = 0; t <= target; ++t) {
                int not_take = dp[i - 1][t];
                int take = (arr[i] <= t) ? dp[i - 1][t - arr[i]] : 0;
                dp[i][t] = (not_take + take) % MOD;
            }
        }

        return dp[n - 1][target];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends