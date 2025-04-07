//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]); 
        }
        queue<int>que;
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(int &v:adj[i]){
                indegree[v]++;
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
        while(!que.empty()){
            int u= que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                    count++;
                }
            }
        }
        if(count==V) return false;
        return true;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends