class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    vector<int>rank;
    vector<int>parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
         if(x_parent == y_parent) return;
         if(rank[x_parent]>rank[y_parent]) parent[y_parent] = x_parent;
         else if(rank[x_parent]<rank[y_parent]) parent[x_parent] = y_parent;
         else{
             parent[x_parent] = y_parent;
             rank[y_parent]++;
         }
    }
    int detectCycle(int v, vector<int> adj[]) {
        // Code here
        parent.resize(v);
        rank.resize(v);
        for(int i=0;i<v;i++){
            parent[i]=i;
            rank[i]=1;
        }
        for(int u =0;u<v;u++){
            for(int &v:adj[u]){
                if(u<v){
                    int parent_u = find(u);
                    int parent_v = find(v);
                    if(parent_u == parent_v) return true;
                    Union(u,v);
                }
            }
        }
        return false;
        
    }
};