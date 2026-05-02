class Solution {
public:

    vector<int> findOrder(int nC, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>inRec(nC,false);
        vector<bool>visited(nC,false);
        vector<int>inDeg(nC,0);
        for(auto &vec:prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
           inDeg[a]++;
        }
        vector<int>res;
        queue<int>que;
        for(int i=0;i<nC;i++){
            if(inDeg[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            res.push_back(curr);
            for(auto &v:adj[curr]){
                inDeg[v]--;
                if(inDeg[v]==0){
                    que.push(v);
                }
            }
        }
        if(res.size()==nC) return res;
        
        return {};
        
    }
};