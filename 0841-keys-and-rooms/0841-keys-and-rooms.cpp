class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);
        queue<int>que;
        que.push(0);
        vis[0] = true;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(auto &v : rooms[node]){
                if(vis[v] != true){
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
        for(bool x : vis){
            if(x == false) return false;
        }
        return true;
        
    }
};