//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
          // Create adjacency list for the graph
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Initialize min-heap for Dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Store distances to nodes, and initialize parent array for path reconstruction
        vector<int> result(n + 1, INT_MAX);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i; // Each node initially points to itself
        }

        result[1] = 0; // Distance to the source node is zero
        pq.push({0, 1}); // Push the source node with distance 0

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;

                if (dist + weight < result[adjNode]) {
                    result[adjNode] = dist + weight;
                    pq.push({dist + weight, adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        // Check if there's a path to the destination node
        if (result[n] == INT_MAX) return {-1};

        // Path reconstruction
        vector<int> path;
        int currentNode = n;
        while (parent[currentNode] != currentNode) {
            path.push_back(currentNode);
            currentNode = parent[currentNode];
        }
        path.push_back(1); // Add the source node
        reverse(path.begin(), path.end()); // Reverse to get the path in correct order

        // Add the weight of the path to the beginning of the list
        path.insert(path.begin(), result[n]);

        return path;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends