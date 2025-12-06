
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]); 
        }
        queue<int>que;
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(int &v :adj[u]){
                indegree[v]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0) que.push(i);
        }
        vector<int>result;
        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0) que.push(v);
            }
        }
        return result;
        
    }
};

