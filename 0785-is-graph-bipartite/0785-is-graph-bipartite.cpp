class Solution {
public:
    bool dfs(vector<int>&col,vector<vector<int>>&graph,int currCol,int u){
        col[u] = currCol;
        for(auto &v:graph[u]){
            if(col[v] == col[u]) return false;
            if(col[v]==-1){
                int colofV = 1 - currCol;
                if(dfs(col,graph,colofV,v)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(col,graph,1,i)==false) return false;
            }
        }
        return true;
    }
};