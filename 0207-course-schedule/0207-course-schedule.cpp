class Solution {
public:
    bool isCycleDFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited, vector<bool>&inRec){
     visited[u] = true;
     inRec[u]= true;
     for(int &v:adj[u]){
        if(!visited[v] and isCycleDFS(adj,v,visited,inRec)) return true;
        else if(inRec[v]==true) return true;
     }
     inRec[u]= false;
     return false;
    }
    bool canFinish(int nC, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<bool>visited(nC,false);
        vector<bool>inRec(nC,false);
        for(auto &vec:prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<nC;i++){
            if(visited[i]==false and isCycleDFS(adj,i,visited,inRec)) return false;

        }
        return true;
    }
};