//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
    void dfsFill(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
        visited[u] = true;
        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfsFill(v, adj, visited, st);
            }
        }
        st.push(u);
    }
    
    void dfsTraversal(int u, vector<vector<int>> &adjReversed, vector<bool> &visited) {
        visited[u] = true;
        for (auto &v : adjReversed[u]) {
            if (!visited[v]) {
                dfsTraversal(v, adjReversed, visited);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
             int V = adj.size();
        stack<int> st;
        vector<bool> visited(V, false);

        // Fill stack with finish order
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }

        // Reverse the graph
        vector<vector<int>> adjRev(V);
        for (int u = 0; u < V; u++) {
            for (auto &v : adj[u]) {
                adjRev[v].push_back(u);
            }
        }

        // Call DFS based on stack order
        int countScc = 0;
        visited = vector<bool>(V, false);
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                dfsTraversal(node, adjRev, visited);
                countScc++;
            }
        }
        
        return countScc;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends