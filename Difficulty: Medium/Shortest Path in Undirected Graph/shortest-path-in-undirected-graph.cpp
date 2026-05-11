class Solution {
  public:
   typedef pair<int,int>P;
   vector<int>solve(unordered_map<int,vector<int>>&adj,int src,vector<int>&res,int V){
       priority_queue<P,vector<P>,greater<P>>minheap;
       res[src]=0;
       minheap.push({0,src});
       while(!minheap.empty()){
           auto curr = minheap.top();
           minheap.pop();
           int currDist = curr.first;
           int node = curr.second;
           for(auto &neigh:adj[node]){
               int newDist = currDist +1;
               if(res[neigh]>newDist){
                   res[neigh] = newDist;
                   minheap.push({newDist,neigh});
               }
           }
       }
       for(int i=0;i<V;i++){
           if(res[i]==INT_MAX){
               res[i]= -1;
           }
       }
       return res;
   }
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>res(V,INT_MAX);
        return solve(adj,src,res,V);
    }
};
