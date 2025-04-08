class Solution {
public:
    bool top(  unordered_map<int,vector<int>>&adj, int n ,vector<int>&indegree){
        queue<int>que;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int u=que.front();
            que.pop();
             count++;
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) {
                   
                    que.push(v);

                }
            }

        }
        if(count==n) return true;
        return false;
    }
    bool canFinish(int nC, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(nC,0);
        for(auto &vec:pre){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

            indegree[a]++;
        }
        return top(adj,nC,indegree);
    }
};