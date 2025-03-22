//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        int n;
int t[100001];

// Function to find the maximum loot from `i` to the end
int f(vector<int>& arr, int i, int end) {
    if (i > end) return 0;
    if (t[i] != -1) return t[i];
    int steal = arr[i] + f(arr, i + 2, end);
    int notSteal = f(arr, i + 1, end);
    return t[i] = max(steal, notSteal);
}
    int maxValue(vector<int>& arr) {
        // your code here
         n = arr.size();
    if (n == 1) return arr[0]; // Edge case: only one house

    // Case 1: Exclude the last house
    memset(t, -1, sizeof(t));
    int case1 = f(arr, 0, n - 2);

    // Case 2: Exclude the first house
    memset(t, -1, sizeof(t));
    int case2 = f(arr, 1, n - 1);

    // Return the maximum of the two cases
    return max(case1, case2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends