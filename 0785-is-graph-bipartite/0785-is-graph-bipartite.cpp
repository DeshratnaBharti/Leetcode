class Solution {
public:
    bool checkBpBFS(vector<vector<int>>&graph,int curr, vector<int>&color,int currColor){
        queue<int>q;
        color[curr]=currColor;

        q.push(curr);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v:graph[u]){
                if(color[v]==color[u]) return false;
                else if(color[v]==-1){
                    color[v]= 1- color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(checkBpBFS(graph,i,color,1)==false) return false;
            }
        }
        return true;
    }
};