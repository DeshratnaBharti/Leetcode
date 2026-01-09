class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>inD(n,false);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            inD[v] = true;
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(inD[i]==false){
                res.push_back(i);
            }
        }
        return res;
    }
};