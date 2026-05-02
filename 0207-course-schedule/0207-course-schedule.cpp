class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        
        unordered_map<int,vector<int>>adj;
        //int n = arr.size();
        //int m = arr[0].size();
       
        for(auto &a:arr){
            int b = a[0];
            int c = a[1];
            adj[c].push_back(b);
        }
        vector<int>inDeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto &v:adj[i]){
                inDeg[v]++;
            }
        }
        queue<int>que;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i]==0){
                que.push(i);
            }
        }
        int count =0;
        while(!que.empty()){
            auto curr = que.front();
            que.pop();
            count++;
            for(auto &v:adj[curr]){
                inDeg[v]--;
                if(inDeg[v]==0)  que.push(v);
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};