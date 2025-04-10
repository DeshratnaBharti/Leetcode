class Solution {
public:
    bool isCycleDFS(vector<vector<int>>&adj,int u,vector<bool>visited,vector<bool>&inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        for(auto &v:adj[u]){
            if(visited[v]==false and isCycleDFS(adj,v,visited,inRecursion)) return true;
            else if(inRecursion[v]==true) return true;
        }
        inRecursion[u]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<bool>visited(n+1,false);
        vector<bool>inRecursion(n+1,false);
        for(int i=0;i<n;i++){
            if(!visited[i] ){
                isCycleDFS(graph,i,visited,inRecursion) ;
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(inRecursion[i]==false){
                result.push_back(i);
            }
        }
        return result;
    }
};