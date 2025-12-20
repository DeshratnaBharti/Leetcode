class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);

    }
    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent == y_parent) return;

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto &vec :edges){
            int u = vec[0];
            int v = vec[1];
            Union(u,v);
        }
        unordered_map<int,int>mp;
        long long remainingNodes =n;
        for(int i=0;i<n;i++){
            int father = find(i);
            mp[father]++;
        }
        long long result =0;
        for(auto &it :mp){
            long long size = it.second;
            result += (size) * (remainingNodes - size);
            remainingNodes -= size;

        }
        return result;
    }
};