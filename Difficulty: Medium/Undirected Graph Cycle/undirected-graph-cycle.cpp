//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to detect cycle in an undirected graph
  

bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited,int parent) {
    
    visited[u] = true; // Mark the starting node as visited
   
        
        for (int &v : adj[u]) {
            if(v==parent) continue;
            if(visited[v]) return true;
            if(isCycleDFS(adj,v,visited,u)) return true;
        }
    
    return false;
}
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
            int n = adj.size();
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && isCycleDFS(adj, i, visited,-1)) {
            return true;
        }
    }
    return false;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends