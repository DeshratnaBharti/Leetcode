//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSlot(vector<int>& parent, int slot) {
    if (parent[slot] == slot) return slot;
    return parent[slot] = findSlot(parent, parent[slot]);
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
         int n = profit.size();
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        arr[i][0] = profit[i];
        arr[i][1] = deadline[i];
    }

    // Sort jobs by profit (descending order)
    sort(arr.begin(), arr.end(), [](auto& vec1, auto& vec2) {
        return vec1[0] > vec2[0];
    });

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i][1]);
    }

    // Initialize parent array for Union-Find
    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++) {
        parent[i] = i;
    }

    int countJobs = 0, jobProfit = 0;
    for (int i = 0; i < n; i++) {
        int availableSlot = findSlot(parent, arr[i][1]);
        if (availableSlot > 0) {
            // Allocate job to this slot
            parent[availableSlot] = findSlot(parent, availableSlot - 1);
            countJobs++;
            jobProfit += arr[i][0];
        }
    }

    return {countJobs, jobProfit};
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends