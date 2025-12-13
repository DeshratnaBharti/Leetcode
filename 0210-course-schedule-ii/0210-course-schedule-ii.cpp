class Solution {
public:
    bool hascycle;
    void dfs( unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,stack<int>&st,vector<int>&inRec){
        visited[u]= true;
        inRec[u]= true;
        for(int &v:adj[u]){
            if(inRec[v]==true){
               hascycle = true;
               return; 
            }
            if(!visited[v]){
                dfs(adj,v,visited,st,inRec);
            }
        }
        st.push(u);
        inRec[u]=false;
    }
    vector<int> findOrder(int nC, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>inRec(nC,false);
        vector<bool>visited(nC,false);
        for(auto &vec:prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

        }
        stack<int>st;
        for(int i=0;i<nC;i++){
            if(!visited[i]) dfs(adj,i,visited,st,inRec);
        }
        if(hascycle==true)return {};
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();

        }
        return res;
        
    }
};