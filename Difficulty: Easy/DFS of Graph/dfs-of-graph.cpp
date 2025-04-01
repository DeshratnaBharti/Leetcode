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
    vector<int> dfs(vector<vector<int>>& adj) {
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
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends