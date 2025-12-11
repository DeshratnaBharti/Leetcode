class Solution {
public:
    vector<int>topoSort(unordered_map<int,vector<int>>&adj,vector<int>&indegree,int n){
        queue<int>que;
        int count =0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                ans.push_back(i);
                que.push(i);
            }
        }
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for(auto &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    que.push(v);
                    ans.push_back(v);
                }
            }
        }
        if(count==n) return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &vec:prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topoSort(adj,indegree,numCourses);
    }
};