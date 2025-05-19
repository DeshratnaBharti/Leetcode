//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   // top down approach
    vector<vector<int>> dp;
    
    int f(vector<int>& arr, int index, int target) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2; 
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }
    
        if (dp[index][target] != -1) return dp[index][target];
    
        int exclude = f(arr, index - 1, target);
        int include = (target >= arr[index]) ? f(arr, index - 1, target - arr[index]) : 0;
    
        return dp[index][target] = exclude + include;
    }

    int countPartitions(vector<int>& arr, int d) {
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        if ((total_sum + d) % 2 != 0) return 0;
    
        int target = (total_sum + d) / 2;
        int n = arr.size();
        
        dp.assign(n, vector<int>(target + 1, -1));
        return f(arr, n - 1, target);
    }


};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends