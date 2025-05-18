//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int f(vector<int>& arr, int target, int i) {
        if (i == n) {
            return (target == 0) ? 1 : 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int take = 0;
        if (target >= arr[i])
            take = f(arr, target - arr[i], i + 1);

        int not_take = f(arr, target, i + 1);

        return dp[i][target] = take + not_take;
    }

    int perfectSum(vector<int>& arr, int target) {
        n = arr.size();

        // To handle 0 targets and possible values
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return f(arr, target, 0);
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