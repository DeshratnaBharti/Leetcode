//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkBipartiteDFS(vector<vector<int>>& adj,int curr,vector<int>&color,int currColor){
        color[curr] = currColor;
        for(int &v : adj[curr]){
            if(color[v]==color[curr]) return false;
            if(color[v]==-1){
                int colorOfv = 1-currColor;
                if(checkBipartiteDFS(adj,v,color,colorOfv)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int v = adj.size();
       vector<int>color(v,-1);
       for(int i=0;i<v;i++){
           if(color[i]==-1){
               if(checkBipartiteDFS(adj,i,color,1)==false){
                   return false;
               }
           }
       }
       return true;
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
        bool ans = obj.isBipartite(adj);
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