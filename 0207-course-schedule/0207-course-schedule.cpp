class Solution {
public:
    bool topoSort( unordered_map<int,vector<int>>&adj,int n,vector<int>&indgree){
        queue<int>que;
        int count =0;
        for(int i=0;i<n;i++){
            if(indgree[i]==0){
                count++;
                que.push(i);
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v:adj[u]){
                indgree[v]--;
                if(indgree[v]==0){
                    count++;
                    que.push(v);
                }
            }
        }
        if(count==n) return true;
        return false;

    }
    bool canFinish(int numCo, vector<vector<int>>& prereq) {
        unordered_map<int,vector<int>>adj;
        vector<int>indgree(numCo,0);
        for(auto &vec:prereq){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);

            indgree[a]++;
        }
            return topoSort(adj,numCo,indgree);
        
    }
};