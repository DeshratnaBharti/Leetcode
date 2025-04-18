class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<int> distance(n + 1, INT_MAX); // Adjust size for 1-based indexing
        unordered_map<int, vector<pair<int, int>>> adj;

        // Build adjacency list
        for (vector<int>& vec : times) {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }

        // BFS
        queue<pair<int, int>> que;
        que.push({src, 0});
        distance[src] = 0;

        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            int node = curr.first;
            int time = curr.second;

            for (auto& v : adj[node]) {
                int new_node = v.first;
                int new_time = v.second;

                // Prevent overflow and update distance
                if (time != INT_MAX && time + new_time < distance[new_node]) {
                    distance[new_node] = time + new_time;
                    que.push({new_node, time + new_time});
                }
            }
        }

        // Calculate maximum delay
        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++) { // Start from 1 for 1-based indexing
            if (distance[i] == INT_MAX) return -1; // Node not reachable
            maxi = max(maxi, distance[i]);
        }

        return maxi;
    }
};
