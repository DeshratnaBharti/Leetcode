//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(vector<vector<int>>& adj,int u, vector<bool>&visited, vector<int>&result){
      if(visited[u]==true) return;
      visited[u] =true;
      result.push_back(u);
      for(int &v : adj[u]){
        if(!visited[v]){
            DFS(adj,v,visited,result);
        }
      }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
       int v = adj.size();
       vector<int>result;
       vector<bool>visited(v,false);
       DFS(adj,0,visited,result);
       return result;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends