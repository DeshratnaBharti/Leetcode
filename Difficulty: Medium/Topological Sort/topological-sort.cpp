
class Solution {
  public:
    void bfs(vector<int>&ind,vector<vector<int>>&adj,vector<int>&res,queue<int>&que){
        
        
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            res.push_back(curr);
            for(auto &v:adj[curr]){
                ind[v]--;
            
                if(ind[v]==0){
                 //res.push_back(v);
                    que.push(v);
                    
                }
        }
            
        }
        
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]); 
        }
        vector<int>ind(V,0);
        for(int u =0;u<V;u++){
            for(int &v:adj[u]){
                ind[v]++;
            }
        }
      
        vector<int>res;
        queue<int>que;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(ind[i]==0){
                que.push(i);
                
            }
        }
        bfs(ind,adj,res,que);
       
        return res;
        
    }
};

