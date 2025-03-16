//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
           int n = arr.size();

    // If array has only one element
    if (n == 1) return 0;

    // If the first element is 0, we cannot move anywhere
    if (arr[0] == 0) return -1;

    int maxReach = arr[0];  // Farthest index we can reach
    int steps = arr[0];     // Steps remaining in the current jump
    int jumps = 1;          // Minimum jumps needed

    for (int i = 1; i < n; i++) {
        // If we've reached the last index
        if (i == n - 1) return jumps;

        // Update the farthest we can reach
        maxReach = max(maxReach, i + arr[i]);

        // Use up a step
        steps--;

        // If no steps are left
        if (steps == 0) {
            jumps++; // Take a jump

            // If the current index is greater than maxReach, we can't proceed further
            if (i >= maxReach) return -1;

            // Reinitialize steps for the new jump
            steps = maxReach - i;
        }
    }

    return -1; 
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends