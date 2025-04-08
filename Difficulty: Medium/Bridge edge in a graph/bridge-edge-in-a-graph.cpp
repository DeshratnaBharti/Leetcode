//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<int>adj[V];
        for(auto &it:edges){
            if((it[0]==c and it[1]==d)or (it[0]==d and it[1]==c)) continue;
            else{
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        }
        vector<int>vis(V,0);
        queue<int>q;
        q.push(c);
        vis[c]=1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        if(vis[d]==0) return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends