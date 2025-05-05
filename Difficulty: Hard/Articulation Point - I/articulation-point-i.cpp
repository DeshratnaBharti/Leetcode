//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public: 
         void DFS(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& disc, vector<int>& low, vector<bool>& artPoint, int& timer) {
        visited[node] = 1;
        disc[node] = low[node] = timer++;
        int child = 0;

        for (int neigh : adj[node]) {
            if (neigh == parent) continue;

            if (visited[neigh]) {
                // Update low value when a back edge is found
                low[node] = min(low[node], disc[neigh]);
            } else {
                child++;
                DFS(neigh, node, adj, visited, disc, low, artPoint, timer);

                // Check articulation point condition
                if (low[neigh] >= disc[node] && parent != -1) artPoint[node] = true;

                low[node] = min(low[node], low[neigh]);
            }
        }

        // Special case for root
        if (child > 1 && parent == -1) artPoint[node] = true;
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
                vector<bool> artPoint(V, false);
        vector<int> disc(V, -1), low(V, -1), visited(V, 0);
        int timer = 0;

        // Run DFS for all unvisited nodes to handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1, adj, visited, disc, low, artPoint, timer);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (artPoint[i]) ans.push_back(i);
        }

        if (ans.empty()) ans.push_back(-1);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends