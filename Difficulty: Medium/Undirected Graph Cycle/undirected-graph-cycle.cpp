//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
       bool isCycleDFS(vector<vector<int>> &adjList, int curr, int parent, vector<bool> &visited) {
        visited[curr] = true;

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                if (isCycleDFS(adjList, neighbor, curr, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
           vector<vector<int>> adjList(V);
        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleDFS(adjList, i, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends