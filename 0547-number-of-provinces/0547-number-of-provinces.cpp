class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&vis){
       queue<int>que;
       que.push(u);
       vis[u] = true;
        while(!que.empty()){
            auto curr = que.front();
            que.pop();
            for(auto &v:adj[curr]){
                if(!vis[v]){
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i != j){
                     adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }

        }
        int count =0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(adj,i,vis);
                count++;
            }
        }
        return count;
    }
};