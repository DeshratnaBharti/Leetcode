
class Solution {
  public:
    void dfs(int u,vector<bool>&vis,vector<vector<int>>&adj,stack<int>&st){
        vis[u] = true;
        for(auto &v:adj[u]){
            
            if(!vis[v]){
               
                dfs(v,vis,adj,st);
                
            }
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]); 
        }
      
        vector<int>result;
        stack<int>st;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
        
    }
};

