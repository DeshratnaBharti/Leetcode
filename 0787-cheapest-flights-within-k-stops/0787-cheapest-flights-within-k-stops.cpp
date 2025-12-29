class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(vector<int>&vec : flights){
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int,int>>que;
        que.push({src,0});
        dist[src] = 0;
        int steps =0;
        while(!que.empty() and steps <= k){
            int N = que.size();
            while(N--){
                int u = que.front().first;
                int c = que.front().second;
                que.pop();
                for(pair<int,int>&P : adj[u]){
                    int v = P.first;
                    int cost = P.second;
                    if(dist[v]>c + cost){
                        dist[v] = c + cost;
                        que.push({v,c+cost});
                    }
                }
            }
            steps++;
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};