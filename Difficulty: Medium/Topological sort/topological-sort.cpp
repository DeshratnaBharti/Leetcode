//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]); 
        }
        queue<int>que;
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(int &v :adj[u]){
                indegree[v]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0) que.push(i);
        }
        vector<int>result;
        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0) que.push(v);
            }
        }
        return result;
        
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
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