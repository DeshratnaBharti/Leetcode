class Solution {
public:
    typedef pair<int,int>P;
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++){
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            adj[a].push_back({b,c});
        }
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<int>res(n+1,INT_MAX);
        res[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int pahleWalaDist = curr.first;
            int srcNode = curr.second;
            for(auto &neighbour:adj[srcNode]){
                int node = neighbour.first;
                int currDist = neighbour.second;
                if(pahleWalaDist + currDist < res[node]) {
                    res[node] = pahleWalaDist + currDist;
                    pq.push({pahleWalaDist+currDist,node});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<res.size();i++){
            ans = max(res[i],ans);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};