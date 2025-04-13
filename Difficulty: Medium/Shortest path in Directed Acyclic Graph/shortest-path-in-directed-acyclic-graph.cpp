//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
           // Step 1: Create adjacency list
    vector<pair<int, int>> adj[V];
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
    }

    // Step 2: Perform Topological Sort
    vector<int> topoSort;
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto &neighbor : adj[i]) {
            indegree[neighbor.first]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for (auto &neighbor : adj[node]) {
            indegree[neighbor.first]--;
            if (indegree[neighbor.first] == 0) q.push(neighbor.first);
        }
    }

    // Step 3: Initialize distance array
    vector<int> distance(V, INT_MAX);
    distance[0] = 0;

    // Step 4: Relax edges in topological order
    for (int node : topoSort) {
        if (distance[node] != INT_MAX) {
            for (auto &neighbor : adj[node]) {
                int v = neighbor.first;
                int wt = neighbor.second;
                if (distance[node] + wt < distance[v]) {
                    distance[v] = distance[node] + wt;
                }
            }
        }
    }

    // Step 5: Replace unreachable distances with -1
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX) {
            distance[i] = -1;
        }
    }

    return distance;

    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends