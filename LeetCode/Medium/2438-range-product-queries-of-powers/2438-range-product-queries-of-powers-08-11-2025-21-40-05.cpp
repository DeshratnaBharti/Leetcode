class Solution {
public:
 int M = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        vector<int>result;
        for(int i=0;i<n;i++){
           if((n&(1<<i)) != 0){
             powers.push_back(1<<i);
           }
        }
        for(auto q:queries){
            int s= q[0];
            int e = q[1];
            long p = 1;
            for(int i=s;i<=e;i++){
                p = (p*powers[i])%M;
            }
            result.push_back(p);
        }
        return result;
    }
};