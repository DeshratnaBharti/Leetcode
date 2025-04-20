//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        queue<pair<int,int>>que;
        vector<int>mark(100000,0);
        que.push({0,start});
        mark[start]=1;
        while(!que.empty()){
            auto curr=que.front();
            que.pop();
            int level = curr.first;
            int new_start=curr.second;
            if(new_start==end) return level;
           
                for (int i = 0; i < n; i++) {
                     int temp_start = (arr[i] * new_start) % 100000;
                     if (!mark[temp_start]) {
                         que.push({level + 1, temp_start});
                         mark[temp_start]=1;
                    
                     }
                }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends