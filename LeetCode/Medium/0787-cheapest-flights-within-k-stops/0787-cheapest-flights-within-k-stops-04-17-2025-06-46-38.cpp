class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(vector<int>&vec:flights){
            int u= vec[0];
            int v=vec[1];
            int cost=vec[2];
            adj[u].push_back({v,cost});
        }
        //bfs
        queue<pair<int,int>>que;
        que.push({src,0});
        distance[src]=0;
        int steps=0;
 while(!que.empty() && steps <= k){
    int N = que.size();
    while(N--){
        auto curr = que.front();
        que.pop();
        int node = curr.first;
        int d = curr.second;
        for(auto &v : adj[node]){
            int new_node = v.first;
            int cost = v.second;
            if(distance[new_node] > d + cost){
                distance[new_node] = d + cost;
                que.push({new_node, d + cost});
            }
        }
    }
    steps++;
}

        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};