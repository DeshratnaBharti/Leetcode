class Solution {
public:
    void bfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            for(int v : adj[curr]) {   // ✅ use curr instead of u
                if(!visited[v]) {
                    visited[v] = true; // ✅ mark visited here
                    que.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                count++;
                bfs(adj, i, visited);
            }
        }
        return count;
    }
};
